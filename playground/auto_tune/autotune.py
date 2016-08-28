#!/bin/env python

import sys
import os
import StringIO
import copy
import time
import math
import subprocess
import multiprocessing
import gc
from sys import argv
import re,shutil
import functools
import random
from itertools import chain
from collections import OrderedDict
from optparse import OptionParser
import copy_reg
import types
import operator
from multiprocessing import Process, Pipe  
from itertools import izip  

utility_path = os.path.dirname(__file__)
include_path = os.path.join(utility_path,'include')
sys.path.append( os.path.expanduser(include_path) )
#sys.path.append( os.path.expanduser('~/git/utility/autoune') )
import miptParser
from autotuneDB import AutotuneDB
from RSD_sensitivity import *
from RCfile_parser import*


#**********************************************************
# for multiprocessing.pool to call class method
def _reduce_method(m):
    if m.im_self is None:
        return getattr, (m.im_class, m.im_func.func_name)
    else:
        return getattr, (m.im_self, m.im_func.func_name)
copy_reg.pickle(types.MethodType, _reduce_method)
#**********************************************************
def spawn(f):
    def fun(pipe,x):
        pipe.send(f(x))
        pipe.close()
    return fun

def parmap(f,X):
    pipe=[Pipe() for x in X]
    proc=[Process(target=spawn(f),args=(c,x)) for x,(p,c) in izip(X,pipe)]
    [p.start() for p in proc]
    [p.join() for p in proc]
    return [p.recv() for (p,c) in pipe]

'''
Golbal utility funciton which can be seen by config.py
'''
def fileread( path ):
    with open(path) as fp:
        contents = fp.readlines()
    return contents


def scaleVec( vec , factor ):
    newvec = [x*factor for x in vec]
    return newvec


def distTo0 (vec):
    mysum = sum( [x*x for x in vec])    
    return math.sqrt( mysum/len(vec) )


def scan_lifringe4_first_line(path, tabletype, layername):
    try:
        with open(path) as f:
            resultList = []
            bFound = False
            bRecording = False
            for idx,line in enumerate(f):
                if line.startswith('PEX TABLE PIECEWISE'):
                    ts = line.strip().split()
                    if ts[3] == tabletype and ts[4].endswith(layername):
                        bFound = True
                        continue
                elif bFound and line.strip().startswith('VALUE'): 
                    bRecording = True
                elif bRecording:
                    if line.strip() == '}':
                        break
                    else:
                        resultList.append( line ) 
                else:
                    continue

        ret = [float(v) for v in resultList[0].split()]
    except:
        ret = [-1]
    # print 'scan_lifringe4_',ret
    return ret


'''
A container class.
Which include all the information required to start a QA
'''
class QARun(object):
    def __init__(self,name):
        self.name = name
        self.qa_path = None
        self.cal_path = None
        self.mipt_settings = None
        self.reportDB = OrderedDict()
        self.score = None


'''
A class that parses TSMC qa report
The result is saved in 'reportDB' as a dictionary.
The key is a tuple with (name,type) , the value is the diference to golden
User should call 'get_dist' to get a tuple of summary. including (min, max, mean, stdev)
'''
class QAItemReport (object):
    '''
    Handle one of the TSMC QA directory
    '''
    def __init__(self, name, qapath):
        self.name = name
        self.qapath = qapath
        self.reportDB = OrderedDict()
        self.parse_report()

    def parse_report(self):
        fileList = [ ('cc', 'QC_Cc/Report_QC_Cc_Summary_SCCB3', 'block net'),
                     ('tc', 'QC_Ct/Report_QC_Ct_Summary_SCCB3', 'block net'),
                     ('sp', 'QC_Spice/Report_QC_Spice_Summary_SCCB3', 'rep item') ]

        for item in fileList:
            type = item[0]
            path = os.path.join(self.qapath, item[1])
            pat = item[2]
            
            if os.path.isfile( path ):
                with open(path) as fp:
                    startIdx = None
                    endIdx = None
                    lines = fp.readlines()
                    tokenLines = []
                    for idx, line in enumerate(lines):
                        tokens = line.strip().split()
                        tokenLines.append( tokens )
                        newpat = ' '.join(tokens)
                        if newpat.startswith(pat):
                            startIdx = idx
                        elif len(tokens)==0 and startIdx != None:
                            endIdx = idx
                            break

                if startIdx != None and endIdx != None and endIdx > startIdx:
                    #-- skip frist line, which is the table header
                    finalItems = tokenLines[startIdx+1:endIdx]
                    for ts in finalItems: 
                        name = ts[0]
                        diff = ts[-1].replace('%','')

                        if self.reportDB.has_key( type ):
                            self.reportDB[type][name] = float(diff)
                        else:
                            self.reportDB[type] = {}
                            self.reportDB[type][name] = float(diff)
        
        #--- debug
        # for key,value in self.reportDB.items():
        #     print key, ' ', value


    def get_dist(self, type):
        '''
        return a dict with min, max, mean, stdev
        '''
        sum = 0
        square_sum = 0
        min = float('inf')
        max = float('-inf')
        vlist = []

        theDict = self.reportDB[type]
        for k,v in theDict.items():
            #-- skip -100
            if  -100.1 < v < -99.9:
                continue
            vlist.append(v)
            sum += v
            if min > v:
                min = v
            if max < v:
                max = v

        if len(vlist) == 0:
            v = float('nan')
            return { 'num': 0, 'min': v, 'max': v, 'mean':v, 'stdev': v }
        else:
            total = len(vlist)
            mean = sum/total
            for i in vlist:
                square_sum += math.pow(i-mean, 2)
            stdev = math.sqrt( square_sum / total )
            return { 'num': total,
                     'min': min,
                     'max': max,
                     'mean': sum/total,
                     'stdev': stdev }


'''
A class to keep a bit string and it's length
Used by AutotuneGA
'''
class Genie (object):
    def __init__(self, len):
        self.len = len
        self.bits = '0' * len
        pass
    
    def mutate(self, N=None): 
        if N==None:
            newbits = []
            for i in self.bits:
                newbits.append(str(Genie.random_bit()))
            self.bits = ''.join( newbits )
        else:
            # randomly choose N bits is change its value
            pos = range(self.len)
            random.shuffle(pos)
            bitsList = list(self.bits)
            for i in range(N):
                idx = pos[i]
                bitsList[idx] = str( Genie.random_bit() )
            self.bits = ''.join( bitsList )

    @staticmethod
    def random_bit():
        return random.randint(0,1)

    @staticmethod
    def random_index(len):
        return random.randint(0,len-1)

    @staticmethod
    def crossover_1_cut( g1, g2 ):
        len1 = g1.len
        len2 = g2.len
        if len1 != len2:
            print 'ERROR, genine size are different'
            exit(1)
        cut = Genie.random_index( len1 )
        # print 'cut ',cut
        newbits1 = g1.bits[:cut] + g2.bits[cut:] 
        newbits2 = g2.bits[:cut] + g1.bits[cut:]

        gnew1 = Genie(len1)
        gnew1.bits = newbits1
        gnew2 = Genie(len1)
        gnew2.bits = newbits2

        return (gnew1, gnew2)



#
#--- run each script by a subprocess
#
class JobProcess (object):
    def __init__(self, id, name, path, depend=None):
        self.id = id 
        self.name = name
        self.running = False
        self.process = None
        self.path = path
        self.depend = depend
        self.finished = False
        pass

    #---to be overwritten
    def do_jobs(self):
        if (self.depend != None):
            while self.depend.value != self.id:
                time.sleep(5)

        os.chdir( self.path )
        print self.name + ' ' + self.path
        sum=0
        for i in range(1000000):
            sum += i*i
        print self.name + ' ' + str(sum)
        print self.name + ' ' + os.getcwd()

        self.depend.value = self.id + 1
        pass

    def start(self, *args):
        self.process = multiprocessing.Process( target=self.do_jobs )
        self.process.start()

    def join(self):
        self.process.join()

    def is_alive(self):
        return self.process.is_alive()
    

class AutotuneJob (JobProcess):
    def __init__(self, id, name, path, depend=None):
        super(AutotuneJob,self).__init__(id, name, path, depend)

    def do_jobs(self):
        if (self.depend != None):
            while self.depend.value != self.id:
                time.sleep(5)

        os.chdir( self.path )
        print self.name + ' -- ' + self.path
        sum=0
        for i in range(1000000):
            sum += i*i+i
        print self.name + ' -- ' + str(sum)
        print self.name + ' -- ' + os.getcwd()

        self.depend.value = self.id + 1



'''
This is served as acontainer objct that holds all the information
in the config.py file. 
'''
class AutotuneConfig (object):
    def __init__(self,fname):
        exec 'self == self'
        self.iteration = 0 
        #--- compile the config script
        execfile(fname)
        assert locals().has_key('tsmc_config'), 'ERROR, find no \'tsmc_config\' function in the config file'

        #--- evaluate the config script
        tsmc_config(self)

        #--- some error checking
        if not hasattr(self, 'mgc_home'):  
            if not os.environ.has_key('MGC_HOME'):
                print 'ERROR, find no mgc_home in config file'
                exit(1)
            else:
                print 'WARNING, found no mgc_home setting in config, use :'
                print '  ', os.environ['MGC_HOME'], 'instead'
                os.environ['PATH'] = os.path.join(os.environ['MGC_HOME'],'bin') + os.pathsep + os.environ['PATH']
        else:
            if os.path.isdir( self.mgc_home ):
                os.environ['MGC_HOME'] = self.mgc_home
                os.environ['PATH'] = os.path.join(self.mgc_home,'bin') + os.pathsep + os.environ['PATH']
            else:
                print 'ERROR, mgc_home setting, path does not exist'
                exit(1)

        assert hasattr(self, 'arcx_config'), 'ERROR, find no calibre_source in config file'
        assert hasattr(self, 'dir_map_v2g'), 'ERROR, find no calibre_source in config file'
        assert hasattr(self, 'mipt_path'), 'ERROR, find no mipt_path in config file'
        assert hasattr(self, 'turbo'), 'ERROR, find no turbo in config file'
        assert hasattr(self, 'run_test'), 'ERROR, find no qa_run in config file'
        assert hasattr(self, 'tunningMode'), 'ERROR, find no tunningMode in config file'
        assert os.path.isfile( self.mipt_path ), 'ERROR, bad mipt_path, file not found'

        if hasattr(self, 'extra_envs'):
            for k, v in self.extra_envs.items():
                os.environ[k] = v

        if self.tunningMode == 'auto':
            assert hasattr(self, 'ga_pool_size'), 'ERROR, find no ga_pool_size in config file'
            assert hasattr(self, 'ga_mutation_ratio'), 'ERROR, find no ga_mutation_ratio in config file'
            assert hasattr(self, 'ga_mutation_bits_ratio'), 'ERROR, find no ga_mutation_bits_ratio in config file'
            assert hasattr(self, 'ga_fit_script'), 'ERROR, find no ga_fit_script in config file'
            assert hasattr(self, 'ga_stop_script'), 'ERROR, find no ga_stop_script in config file'
            assert hasattr(self, 'ga_constraints'), 'ERROR, find no ga_constraints in config file'
            assert len(self.ga_constraints) >=1 , 'ERROR, should have at least one parameter for ga tunning'
        
        elif self.tunningMode == 'explore_RSD':
            assert hasattr(self, 'rsd_explore_constraint'), 'ERROR, find no rsd_explore in config file'
            assert len(self.rsd_explore_constraint) >=1 , 'ERROR, should have at least one parameter for rsd explore mode'
        
        elif self.tunningMode == 'explore_QA':
            flag = 0
            if hasattr(self,'rsd_db_1'): 
                flag = 1
                assert "" != self.rsd_db_1, "ERROR, \"rsd_db_1\" empty"
            if hasattr(self,'rsd_db_2'): 
                flag = 1
                assert "" != self.rsd_db_2, "ERROR, \"rsd_db_2\" empty"
            if 0 == flag:
                print "ERROR, explore_QA mode must provide \"self.rsd_db_1\""
        else: #user mode
            assert hasattr(self, 'exp_names'), 'ERROR, find no exp_names in config'
            assert hasattr(self, 'exp_props'), 'ERROR, find no exp_props in config'
            exp_num = len(self.exp_names)
            for k in self.exp_props:
                if type(k) is list:
                    assert len(k) == exp_num+1, 'ERROR, inconsisent size of exp_names and exp_rpops'
                    for idx in range(0,len(k)):
                        if idx==0:
                            assert type(k[idx])==str, 'ERROR, bad frist token of exp_props, should be string type'
                        else:
                            assert type(k[idx])==float, 'ERROR, bad value token of exp_props, should be float type'

        #--- build ecntral mipt stack
        print "Parsing MIPT file \"",self.mipt_path,"\""
        parser  = miptParser.MiptParser( self.mipt_path )
        parser.parse()
        self.miptstack = miptParser.MiptStack( parser._mipt )
        self.miptstack.construct()

        #--- display the current setting



class AutotuneJobManager (object):
    '''
    This is about thow to run jobs for each qa object
    It neds the config object and the qaobj list as input
    '''
    def __init__(self, config, db):
        self.config = config
        self.db = db

    def submit_qa (self, qalist):
        #--- parepare all the run directories
        for qaobj in qalist:
            os.makedirs( qaobj.qa_path )
            os.makedirs( qaobj.cal_path )
            gstack = self.config.miptstack.clone()
            gstack.update_prop( qaobj.mipt_settings )
            with open(qaobj.mipt_path, 'w') as fp:
                fp.write( gstack.mipt_str() )
            del gstack
            
            #--- save the setting in each qa folder
            with open(os.path.join(qaobj.qa_path, 'mipt_setting.log'), 'w') as fp:
                for k,v in qaobj.mipt_settings.items():
                    fp.write(' '.join([k, str(v), '\n']))

            with open(os.path.join(qaobj.qa_path, 'calibre_2016_source.csh'), 'w') as fp:
                fp.write('#!/bin/csh -f' + '\n')
                for k,v in self.config.extra_envs.items():
                    fp.write('setenv ' + k + ' ' + v + '\n')
                fp.write('setenv MGC_HOME ' + os.environ['MGC_HOME'] + '\n')
                fp.write(r'set path = ($MGC_HOME/bin $path)' + '\n' )

            #--- copy dir_map_v2g
            if os.path.isfile(self.config.dir_map_v2g):
                shutil.copy( self.config.dir_map_v2g, qaobj.qa_path )

            #--- copy arcx.cfg and replace rules setting
            if os.path.isfile(self.config.arcx_config):
                with open(self.config.arcx_config,'r') as fp:
                    contents = fp.read()
                contents = re.sub( r'RCX_RULES\s*=\s*\S*', 'RCX_RULES = '+ os.path.join( qaobj.cal_path, 'rules'), contents)
                contents = re.sub( r'TOOL_VERSION_RCX\s*=\s*\S*', 'TOOL_VERSION_RCX = '+ os.path.join( qaobj.qa_path, 'calibre_2016_source.csh'), contents)
                with open(os.path.join(qaobj.qa_path, 'arcx.cfg'), 'w') as fp:
                    fp.write( contents )

        #--- invoke the process
        waiting_qaobjs = qalist[:]
        running_processes = []
        scoreList = [] 
        while len(waiting_qaobjs)>0 or len(running_processes)>0:
            updated_running_processes = []
            for p,q in running_processes:
                if p.is_alive():
                    updated_running_processes.append( (p,q) )
                else:
                    p.join() 
                    scoreList.append( self.collect_qa_result(q))
            running_processes = updated_running_processes
            #--- grab jobs from watting queue, start them, and add them to running queue.
            #
            available = self.config.turbo - len(running_processes) 
            prepared_qaobjs = waiting_qaobjs[:available]
            waiting_qaobjs = waiting_qaobjs[available:]
    
            for qaobj in prepared_qaobjs:
                newp = multiprocessing.Process( target=self.config.run_test, args=(qaobj,) )
                running_processes.append( (newp, qaobj) )
                newp.start()
                print 'Adding --- ', qaobj.name

            print '---'
            for p,q in running_processes:
                print 'Running ---', q.name
            print '---'
 
            time.sleep(3)
    
        return scoreList

    def collect_qa_result(self, qaobj):

        print '----', qaobj.name, '----'
        score = self.config.ga_fit_script( qaobj)
        print '  ', qaobj.name, ' score ', score
        mipt_setting = qaobj.mipt_settings 
        for k,v in mipt_setting.items():
            print '  {0} = {1}'.format(k, v)
        #scoreList.append( score ) 

        #--- update each qa result to AutotuneDB
        for idx, k in enumerate(self.db.keys):
            print idx, k
            #print "qa key:", qaobj.mipt_settings.keys()[idx]
            #print "dbkey:", k
            assert qaobj.mipt_settings.keys()[idx] == k, 'DB keys does not match to miptsetting keys'
        
        settingTuple = tuple( [float(item) for item in qaobj.mipt_settings.values() ])
        for k, v in qaobj.reportDB.items():
            self.db.add_qa_result( settingTuple, k, v)

        self.db.dumpDB(self.config.rsd_exp_db)
        return score


    #TODO: Unused function ?
    def run_xcalibrate_exp(self, qaobj):
        os.makedirs( qaobj.qa_path )
        os.makedirs( qaobj.cal_path )
        exp_mipt_stack = self.config.miptstack.clone()
        exp_mipt_stack.update_prop( qaobj.mipt_settings )
        with open(qaobj.mipt_path, 'w') as fp:
            fp.write( exp_mipt_stack.mipt_str() )
        del exp_mipt_stack
        
        #--- save the setting in each qa folder
        with open(os.path.join(qaobj.qa_path, 'mipt_setting.log'), 'w') as fp:
            for k,v in qaobj.mipt_settings.items():
                fp.write(' '.join([k, str(v), '\n']))

        with open(os.path.join(qaobj.qa_path, 'calibre_2016_source.csh'), 'w') as fp:
            fp.write('#!/bin/csh -f' + '\n')
            for k,v in self.config.extra_envs.items():
                fp.write('setenv ' + k + ' ' + v + '\n')
            fp.write('setenv MGC_HOME ' + os.environ['MGC_HOME'] + '\n')
            fp.write(r'set path = ($MGC_HOME/bin $path)')

        calpath = os.path.expanduser(qaobj.cal_path)
        rulepath = os.path.join(calpath, 'rules.FS')
        
        ret_tbl = None
        #CorrectionTbl_info
        try:
            self.config.run_test(qaobj) # xcalibrate exception handle
            ruleFS_parser = RCfile_Parser(rulepath) # need full path info when output report
            ruleFS_parser.parse(qaobj.seed_layer)
            ruleFS_parser.eval_correction_Tbl_score()
            ret_tbl = ruleFS_parser.lifringe4_tbl
        except:
            print calpath + " xcalibrate execute fail"
            ret_tbl = CorrectionTbl_info(rulepath,[],[])
        
        ret_tbl.fname = qaobj.name # shorten data when write xls format
        ret_tbl.mipt_settings = qaobj.mipt_settings
        ret_tbl.rsd_enclosure = qaobj.mipt_settings[qaobj.seed_layer+'.rsd_enclosure']
        ret_tbl.rsd_thickness = qaobj.mipt_settings[qaobj.seed_layer+'.rsd_thickness']
        ret_tbl.rsd_spacing = qaobj.mipt_settings[qaobj.seed_layer+'.rsd_spacing']

        return ret_tbl


    #TODO: Unsued function ?
    def xcalibrate_exp (self, qalist):

        tgt_exp_res = []
        while qalist:
            tmp_qalst = []
            for i in range(0,self.config.rsd_exp_thread):
                tmp_qalst.append(qalist.pop())
                if not qalist: break
            tgt_exp_res.extend(parmap(self.run_xcalibrate_exp,tmp_qalst))
            tmp_qalst[:] = []
        qalist[:] = []

        return tgt_exp_res

class AutotuneGA (object):
    '''
    To control GA related flow. 
    It takes the config object as input.
    '''
    def __init__(self, configobj, jobmgr ):
        self.bitslen = 8
        self.poolsize = 20
        self.pool = []
        self.iteration = 0
        self.expidx = 0
        
        self.mutation_ratio = 0.2
        self.assignments = OrderedDict()
        self.constraints = OrderedDict()
        self.samples = OrderedDict()
        self.config = configobj
        self.process_ga_constraints()
        self.jobmgr = jobmgr


    def init_genies(self):
        keys = list(self.samples.keys())
        mysamples = [OrderedDict( zip(keys,vals) ) for vals in zip( *(self.samples[k] for k in keys) )]
        sample_genies = [self.mipt_to_genie(k) for k in mysamples]
        self.pool.extend( sample_genies )
        for i in range( self.poolsize - len(self.pool)):
            self.pool.append( self.new_genie() )


    def new_genie(self):
        '''
        randomly generate genie bits based on ga constraints
        ''' 
        tempbits = []
        for k, v in self.constraints.items():
            name = k
            lower,higher, scale, myrange, bitsize, samples  = v
            randv = random.randint(0, myrange)
            randbinary = bin(randv)[2:]
            paddedbinary = '0' * (bitsize - len(randbinary)) + randbinary
            # print 'new_genie: ', name, lower, higher, scale, myrange, randv, paddedbinary
            tempbits.append( paddedbinary )
        finalbits = ''.join( tempbits )

        assert len(finalbits)==self.bitslen, 'Inconsistent genie bits size'
        g = Genie( self.bitslen )
        g.bits = finalbits
        return g


    def genie_to_mipt(self, genie):
        '''
        Unlike mipt_to_genie,
        this function will need to evaluate the assignments as well
        '''
        startIdx = 0
        mipt_settings = OrderedDict()
        for k, v in self.constraints.items():
            name = k
            lower,higher, scale, myrange, bitsize, samples  = v
            segbits = genie.bits[startIdx:startIdx+bitsize]
            segv = int(segbits,2)
            miptv = lower + (float(segv) / scale)
            mipt_settings[name] = str(miptv)
            startIdx += bitsize

        #---evaluate assignments
        for k, v in self.assignments.items():
            name = k
            replacedv = v
            for k1, v1 in mipt_settings.items():
                replacedv = replacedv.replace( k1, str(v1) )
            newv = eval( replacedv )
            mipt_settings[k] = str(newv)
        return mipt_settings


    def mipt_to_genie(self, mipt_settings):
        '''
        mipt_setting should be an OrderedDict
        in the format of :
            { 
              'layerA.a' : 0.02, 
              'layerB.b': 0.0023,
              ...
            }
        '''
        tempbits = []
        for k, v in self.constraints.items():
            name = k
            lower,higher, scale, myrange, bitsize, samples  = v
            myv = mipt_settings[name]
            intmyv = int(myv * scale - lower * scale)
            mybinary = bin(intmyv)[2:]
            paddedbinary = '0' * (bitsize - len(mybinary)) + mybinary
            # print 'mipt_to_genie: ', lower, higher, scale, myrange, myv, intmyv, paddedbinary
            tempbits.append( paddedbinary )
        finalbits = ''.join( tempbits )
        g = Genie(self.bitslen)
        g.bits = finalbits
        return g


    def process_ga_constraints (self):
        '''
        Part of the initialization of this object.
        Read constraints from the config object, 
        create 'constraint' and 'assignments' accordingly
        '''
        fullbitsize = 0
        for item in self.config.ga_constraints:
            if type(item) is list:
                name = item[0].strip()
                lower = item[1]
                higher = item[2]
                scale = item[3]
                samples = item[4:]
                myrange = int((higher - lower) * scale)
                bitsize = len(bin(myrange)[2:])
                fullbitsize += bitsize
                self.constraints[name] = (lower, higher, scale, myrange, bitsize, samples)
                self.samples[name] = samples
            else:
                name = item[0].strip()
                expression = item[1].strip()
                self.assignments[name] = expression
        
        assert len(self.samples)==0 or len(self.samples)==len(self.constraints)
        self.bitslen = fullbitsize
        self.poolsize = self.config.ga_pool_size

    def evaluate_genies(self):
        '''
        This is called by 'iterate'
        Evaluate each qaobjs in the GA pool, 
        '''
        qalist = []
        #--. create folder and mipt file
        for g in self.pool:
            exp_name = 'exp_' + str(self.iteration) + '_' + str(self.expidx)
            self.expidx += 1
            qaobj = QARun( exp_name )
            qaobj.mipt_settings = self.genie_to_mipt( g )
            qaobj.qa_path = os.path.join( os.getcwd(), exp_name)
            qaobj.cal_path = os.path.join( qaobj.qa_path, 'calibration')
            qaobj.mipt_path = os.path.join( qaobj.cal_path, exp_name + '.mipt') 
            qalist.append( qaobj )

        return self.jobmgr.submit_qa( qalist )

        
    def evaluate_genies_example(self):
        '''
        Fake evaluation function for testing
        (x - 0.013)^2 + (y - 0.015)^2 = 0
        '''
        scoreList = []

        print '-------- evaluation --------'
        print 'Iteration: ', self.iteration

        # print '--- iteration ----' , self.iteration
        for g in self.pool:
            mipt_settings = self.genie_to_mipt( g )
            a = mipt_settings['p_gpoly_lvt.rsd_spacing']
            b = mipt_settings['n_gpoly_svt.rsd_spacing']
            scoreinverse = (pow(a-0.0131, 2) + pow(b - 0.0112, 2))
            if scoreinverse == 0:
                score = 10000000
            else:
                score = 0.001 / scoreinverse
            print '  ', a, b, score
            scoreList.append(score)

        return scoreList


    def next_iteration(self):
        '''
        called by iterate
        Keep record the current iteration index
        '''
        self.iteration += 1
        return not self.config.ga_stop_script( self )


    def iterate(self):
        '''
        The main logic.
        1. create a pool of genies
        2. evaluate the score for the genie list
        2.1 create a wheel based on the score
        3. crossover pair of genie to create new pair of genie
        4. randomly mutate the genie
        5. loop again
        '''
        while self.next_iteration():

            if self.iteration == 1:
                self.init_genies()

            #---- to be derived
            scoreList = self.evaluate_genies()

            scoreSum = sum(scoreList)
            tupleList = zip(scoreList, self.pool)
            sortedTupleList = sorted( tupleList, key=lambda x: x[0]) 

            #--- debug
            # print '------- iteration --------', self.iteration
            # for i in range(1,5):
            #     print sortedTupleList[-i][0], sortedTupleList[-i][1].bits
            
            #--- Make a lottery wheel
            probablity_wheel_size = 10 * self.poolsize
            wheel = []
            for s,g in sortedTupleList:
                count = int(probablity_wheel_size * s / scoreSum)
                wheel.extend( [g]*count )

            #--- crossover
            newpool = []
            for i in range( self.poolsize ):
                randa = random.randrange( len(wheel) )
                randb = random.randrange( len(wheel) )
                while randb == randa:
                    randb = random.randrange( len(wheel) )

                randg1 = wheel[ randa ]
                randg2 = wheel[ randb ]
                newg1, newg2 = Genie.crossover_1_cut( randg1, randg2 )
                #--- crossover returns two genie
                #    rnadomly pick one of it to be the next around genie
                if Genie.random_bit() == 0:
                    newpool.append( newg1 )
                else:
                    newpool.append( newg2 )

            self.pool = newpool

            #--- mutation
            #    TODO:, mutatation bit number shoud depend on the score.
            for g in self.pool:
                g.mutate( int( self.mutation_ratio * self.bitslen ) )



class Autotune (object):
    '''
    Entry for the two autotune flow, GA or user-defined.
    '''
    def __init__(self, configf):
        self.config = AutotuneConfig( configf )
        #read previous db to resue previous status
        #--- to initialize the DB, we need the keys for DB
        #    jobmgr is passed around to run jobs and collect the result db
        #
        self.db = None
        if self.config.tunningMode == 'auto': 
            dbkeys = [x[0] for x in self.config.ga_constraints]
        elif self.config.tunningMode == 'explore_RSD':
            dbkeys = tuple([x[0] for x in self.config.rsd_explore_constraint])
        elif self.config.tunningMode == 'explore_QA':
            dbkeys = self.read_user_db() # fill in var: self.rsd_db_1 and self.rsd_db_2
            dbkeys += (tuple([x[0] for x in self.config.assignment]))

            if hasattr(self.config,'rsd_exp_db') and os.path.exists(self.config.rsd_exp_db):
                tmpdb = AutotuneDB(infile=self.config.rsd_exp_db)
                if (tmpdb.keys == dbkeys):
                    self.db = tmpdb
                    print "Read db:",self.config.rsd_exp_db
                else:
                    os.rename(self.config.rsd_exp_db, self.config.rsd_exp_db+".bk")

        else: #user mode
            dbkeys = [x[0] for x in self.config.exp_props]
        
        if None == self.db :
            self.db = AutotuneDB(keys = tuple(dbkeys) )

        self.jobmgr = AutotuneJobManager( self.config, self.db )
        if self.config.tunningMode == 'auto': 
            self.ga = AutotuneGA(self.config, self.jobmgr )
        elif self.config.tunningMode == 'explore_RSD':
            self.explore = RSD_sensitive_explor(self.jobmgr)
        else: #user mode & explore_QA mode
            self.ga = None

    def read_user_db(self):
        # tunningMode = 'explore_QA'
        # get the rsd key in user provided db file
        ret_key = ()
        self.rsd_db_1 = None
        self.rsd_db_2 = None
        if hasattr(self.config,'rsd_db_1'): 
            self.rsd_db_1 = AutotuneDB(infile=self.config.rsd_db_1)
            ret_key += self.rsd_db_1.keys
        if hasattr(self.config,'rsd_db_2'): 
            self.rsd_db_2 = AutotuneDB(infile=self.config.rsd_db_2)
            ret_key += self.rsd_db_2.keys
        return ret_key

    def process_non_ga_constraints (self, exp_names, exp_props):
        '''
        Scan the exp_names and exp_props, find direct settings and assignments
        Translate it to a list of mipt_setting dict
        '''
        direct_settings = [ x for x in exp_props if type(x) is list]
        assignments = [ x for x in exp_props if type(x) is tuple] 

        keys = [x[0].strip() for x in direct_settings]
        allvals = [x[y] for y in range(1, len(exp_names)+1) for x in direct_settings]
        valslist = [ allvals[x:x+len(direct_settings)] for x in range(0, len(allvals), len(direct_settings)) ]
        miptsetting_list = [OrderedDict( zip(keys, vals) ) for vals in valslist]

        #---evaluate assignments
        for miptsetting in miptsetting_list:
            for k, v in assignments:
                name = k.strip()
                replacedv = v.strip()
                print "replacedv==", replacedv
                for k1, v1 in miptsetting.items():
                    replacedv = replacedv.replace( k1, str(v1) )
                    print "==replacedv", replacedv
                newv = eval( replacedv )
                miptsetting[k] = newv

        return miptsetting_list
    
    def get_exp_mipt_setting(self,keys , sorted_dict, comb_num):
        #return top $comb_num expriment rsd setting
        #miptsetting OrderedDict([('p_gpoly_lvt.rsd_enclosure', -0.003), ('p_gpoly_lvt.rsd_spacing', 0.0097), ('p_gpoly_lvt.rsd_thickness', 0.00081), ('n_gpoly_lvt.rsd_enclosure', -0.003), ('n_gpoly_lvt.rsd_spacing', 0.0097), ('n_gpoly_lvt.rsd_thickness', 0.0005), ('p_gpoly_svt.rsd_enclosure', -0.003), ('p_gpoly_svt.rsd_spacing', 0.0097), ('p_gpoly_svt.rsd_thickness', 0.00081), ('n_gpoly_svt.rsd_enclosure', -0.003), ('n_gpoly_svt.rsd_spacing', 0.0097), ('n_gpoly_svt.rsd_thickness', 0.0005)])

        miptsetting_list = []
        idx =0
        for rsd,v in sorted_dict:
            if idx >= comb_num: break;
            miptsetting_list.append(OrderedDict(zip(keys, rsd)))
            idx+=1
        
        return miptsetting_list

    def start(self):
        if self.config.tunningMode == 'auto': 
            '''
            GA flow
            '''
            self.ga.iterate()
        elif self.config.tunningMode== 'explore_RSD':
            self.explore.run_profiling()
        elif self.config.tunningMode== 'user':
            '''
            Non GA flow
            '''
            exp_names = self.config.exp_names
            exp_props = self.config.exp_props 
            miptsetting_list = self.process_non_ga_constraints( exp_names, exp_props)
            qalist = []
            #--. create folder and mipt file
            for idx, miptsetting in enumerate(miptsetting_list):
                #print "miptsetting", miptsetting
                exp_name = exp_names[idx]
                qaobj = QARun( exp_name )
                qalist.append( qaobj )
                qaobj.mipt_settings = miptsetting
                qaobj.qa_path = os.path.join( os.getcwd(), exp_name)
                qaobj.cal_path = os.path.join( qaobj.qa_path, 'calibration')
                qaobj.mipt_path = os.path.join( qaobj.cal_path, exp_name + '.mipt') 
            self.jobmgr.submit_qa(qalist)
                   
        elif self.config.tunningMode== 'explore_QA':
            '''
            Non GA flow - base on explore_RSD mode output db
            '''
            tried_history = {}
            for exist_key in self.db.mipt_setting_map:
                tried_history[exist_key] = 1
                #print "exist key:", exist_key

            rsd_exp_db_1_dict_sort = {}
            rsd_exp_db_2_dict_sort = {}
            exp_db1_keys = ()
            exp_db2_keys = ()
            if self.rsd_db_1:
                #print "read rsd_db_1"
                rsd_exp_db_dict = {} # rsd_exp_db_dict[tuple] = cost
                exp_db1_keys = self.rsd_db_1.keys
                for k, v in self.rsd_db_1.mipt_setting_map.items():
                    rsd_exp_db_dict[k] = abs(self.rsd_db_1.qa_map[v]['correciton_cost'])

                rsd_exp_db_1_dict_sort= sorted(rsd_exp_db_dict.items(), key=operator.itemgetter(1))
                del self.rsd_db_1
                del rsd_exp_db_dict

            if self.rsd_db_2:
                #print "read rsd_db_2"
                rsd_exp_db_dict = {} # rsd_exp_db_dict[tuple] = cost
                exp_db2_keys = self.rsd_db_2.keys
                for k, v in self.rsd_db_2.mipt_setting_map.items():
                    rsd_exp_db_dict[k] = abs(self.rsd_db_2.qa_map[v]['correciton_cost'])

                rsd_exp_db_2_dict_sort= sorted(rsd_exp_db_dict.items(), key=operator.itemgetter(1))
                del self.rsd_db_2
                del rsd_exp_db_dict

            exp_serial = 1
            db_cnt = 5
            qalist = []
            while db_cnt < len(rsd_exp_db_1_dict_sort) or db_cnt < len(rsd_exp_db_2_dict_sort):
                mipt_set_lst = [self.get_exp_mipt_setting(exp_db1_keys,rsd_exp_db_1_dict_sort,db_cnt) , self.get_exp_mipt_setting(exp_db2_keys,rsd_exp_db_2_dict_sort,db_cnt)]
                mipt_set_lst = [x for x in mipt_set_lst if x]
                #print len(mipt_set_lst), mipt_set_lst
                comb_miptsetting_lst=[]
                for mipt_set1 in mipt_set_lst[0]:
                    if 1 < len(mipt_set_lst): 
                        for mipt_set2 in mipt_set_lst[1]:
                            comb_miptsetting_lst.append(mipt_set1.items()+mipt_set2.items())
                    else:
                        comb_miptsetting_lst.append([mipt_set1.items()])

                for mipt_set in comb_miptsetting_lst:
                    tmp_miptsetting = OrderedDict()
                    for k,e in mipt_set: 
                        tmp_miptsetting[k]=e
                    
                    #print self.config.assignment
                    for k, v in self.config.assignment:
                        name = k.strip()
                        replacedv = v.strip()
                        for k1, v1 in tmp_miptsetting.items():
                            replacedv = replacedv.replace( k1, str(v1) )
                        try:
                            newv = eval( replacedv )
                            tmp_miptsetting[k] = newv
                        except:
                            pass

                    if tuple(tmp_miptsetting.values()) in tried_history: 
                        #print "skip!!",tmp_miptsetting.values()
                        continue
                    tried_history[tuple(tmp_miptsetting.values())] = 1
                    #print "test:", len(tried_history), tried_history
                    #print "run: ", tuple(tmp_miptsetting.keys())
                    #print "run: ", tuple(tmp_miptsetting.values())
                    exp_name = "exp_" + str(exp_serial)
                    exp_serial +=1
                    qaobj = QARun( exp_name )
                    qalist.append( qaobj )
                    qaobj.mipt_settings = tmp_miptsetting
                    #tmp_miptsetting.clear()
                    qaobj.qa_path = os.path.join( os.getcwd(), exp_name)
                    qaobj.cal_path = os.path.join( qaobj.qa_path, 'calibration')
                    qaobj.mipt_path = os.path.join( qaobj.cal_path, exp_name + '.mipt')
                self.jobmgr.submit_qa(qalist)
                qalist[:] = []
                db_cnt += 5
               
        else:
            print "ERROR: ",self.config.tunningMode, "not support"        

        #---TODO: save the DB to a file, even if there's problem in any part of the flow.


    def dumpDB(self, fname='out.db'):
        self.db.dumpDB( fname )

            
'''
Below are all test functions
'''

def test_MiptStack_update_prop( inputfile ):
    parser1 = miptParser.MiptParser( inputfile )
    parser1.parse()
    stack1 = miptParser.MiptStack( parser1._mipt )
    stack1.construct()
    stack2 = stack1.clone()
    
    stack2.update_prop( {'n_gpoly_svt.zbottom': '0513'} )
    stack2.update_prop( {'p_gpoly_svt.abc': '0513'} )
    stack2.update_prop( {'n_gpoly_srm.rsd_thickness': '0.04444'} )

    with open('out1.mipt', 'w') as fout1:
        fout1.write( stack1.mipt_str() )

    with open('out2.mipt', 'w') as fout2:
        fout2.write( stack2.mipt_str() )


def test_JobProcess():

    control = multiprocessing.Value('i',0)
    p1 = AutotuneJob(0, 'test1', os.getcwd() , control )
    p2 = AutotuneJob(1, 'test2', os.getcwd() , control )
    p3 = AutotuneJob(2, 'test3', os.getcwd() , control )

    p3.start()
    p2.start()
    p1.start()

    p1.join()
    p2.join()
    p3.join()


def test_config(fname):
    myconfig = AutotuneConfig(fname)
    # myconfig.tsmc_config()
  
    for line in myconfig.calibre_source:
        print line.strip()

    for line in myconfig.arcx_config:
        print line.strip()

    for line in myconfig.dir_map_v2g:
        print line.strip()

    print myconfig.run_test

    for item in myconfig.exp_names:
        print item

    for item in myconfig.exp_props:
        print item

    print myconfig.ga_pool_size
    print myconfig.ga_mutation_ratio
    print myconfig.ga_mutation_bits_ratio

    print myconfig.ga_fit_script
    print myconfig.ga_stop_script

    print myconfig.ga_constraints

    qaobj = QARun('FakeQARun')
    qaobj.qa_path = '~/git/utility/autotune/example_qa'
    qaobj.cal_path = '~/git/utility/autotune/example_qa/calibration'
    print myconfig.ga_fit_script( qaobj )

    print qaobj.reportDB
    
    class TestGA:
        def __init__(self):
            self.iteration = 0

    tga = TestGA()
    print myconfig.ga_stop_script( tga )




def test_QAItemReport():
    qaobj = QAItemReport('QA','example_qa/N7_v0d1_core_small_20151117_run')
    print qaobj.get_dist('cc')
    # print qaobj.get_dist('tc')
    qaobj = QAItemReport('QA','example_qa/n7_v0.1_pode_stdcell_fullMD_SCLD_A2_run')
    print qaobj.get_dist('sp')
    # print qaobj.get_dist('cc')
    # print qaobj.get_dist('tc')



def test_scaleVec():
    vec = [1.0, 2.1, 0.0102, 0.002]
    print scaleVec( vec , 10000)


def test_scan_lifringe4_first_line():
    ret = scan_lifringe4_first_line( './rules.FS', 'LIFRINGE4', 'n_gpoly_lvt')
    print ret


def test_genie():
    genie = Genie( 8 )
    genie.mutate()
    genie2 = Genie( 8 )
    genie2.mutate()

    print genie.bits
    print genie2.bits
    g1, g2 = Genie.crossover_1_cut(genie, genie2)
    print g1.bits, ' ', g2.bits

    genie = Genie( 8 )
    genie.mutate( 4 )
    print genie.bits


# def test_GA():
#     ga = GA() 
#     ga.poolsize = 20;
#     ga.bitslen = 8
#     ga.init_genies()
#     for g in ga.pool:
#         print g.bits
#     ga.iterate()


def test_autotuneGA():
    config = AutotuneConfig('config.py')

    dbkeys = [x[0] for x in config.ga_constraints]
    db = AutotuneDB( keys=tuple(dbkeys) )
    jobmgr = AutotuneJobManager( config, db)
    ga = AutotuneGA( config, jobmgr )
    ga.iterate()

    # g = ga.new_genie()
    # print g.bits

    # mipt_settings = ga.genie_to_mipt( g )
    # for k,v in mipt_settings.items():
    #     print k, v
    #ga.init_genies()
    

def test_autotune():
    at = Autotune( 'config.py' )
    at.start()
    at.dumpDB('out.db')
    db = AutotuneDB(infile='out.db')
    db.dump()


if __name__ == '__main__':
    # test_MiptStack_update_prop('test.mipt')
    # test_JobProcess()
    # test_QAItemReport()
    # test_config('config.py')
    # test_scaleVec()
    # test_scan_lifringe4_first_line()
    # test_genie()
    # test_GA()
    # test_autotuneGA()
    # test_autotune()
    #myconfig = AutotuneConfig('config.py')
    #print "constraints:",myconfig.ga_constraints
    #print "explore constraints:",myconfig.rsd_explore
    #dbkeys = [x[0] for x in myconfig.ga_constraints]
    #print dbkeys
    #exit(1)

    #--- args parsing
    optparser = OptionParser()
    optparser.add_option('-c',default='config.py',dest='config')
    optparser.add_option('-o',default='out.db',dest='db')
    (options, args) = optparser.parse_args()

    if not os.path.isfile( options.config ):
        print 'ERROR, cannot file config file', options.config
        exit(1)

    #--- start tuning
    at = Autotune( options.config )
    #for devn, devobj in at.config.miptstack.deviceMap.items():
    #    print devobj.seed.name + " ",
    #print " "

    at.start()
    #at.dumpDB( options.db )















