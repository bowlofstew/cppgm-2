
'''
This is a member function of the class 'AutotuneConfig'
'''
def tsmc_config (configObj):
    print 'Start loading config...'
    myfolder                  = os.getcwd()
    #configObj.mgc_home        = '/Users/yung/Dropbox/tmp/autotune'
    #configObj.mgc_home        = '/home/brlin/calibre_bin/aoi_cal_2016.3_0.3808tb'
    configObj.mgc_home        = '/twh/builds/Calibre/cal_nightly/calibre_2016_2/ic/ic_superproj/aoi/Mgc_home'
    configObj.arcx_config     = './example_qa/arcx.3d.cfg'
    configObj.dir_map_v2g     = './example_qa/dir_map_v2g'
    configObj.mipt_path       = './cln7_1p12m_1x1xa1ya4y2yy2z_ut-alrdl_typical.mipt'
    configObj.turbo           = 4
    configObj.rsd_exp_thread  = 10
    configObj.rsd_exp_db = "./io_exp.db"
    configObj.extra_envs      = {}
    configObj.tunningMode     = 'explore_QA' #-- auto|user|explore_RSD|explore_QA

    def run_func ( *args ):
        qaobj, = args
        name  = qaobj.name
        mipt = qaobj.mipt_path
        os.chdir( qaobj.cal_path)
        os.environ['XCAL_FINFET_CAL_DIR'] = '/net/roll/data/xcalibrate/7nm_v0.5/0606_qc_package/normal_fin_count/cal.out'
        os.environ['XCAL_INTRINSIC_SUBTRACT_ALL'] = 'on'
        os.environ['XCAL_DISABLE_ENCRYPT'] = 'on'
        os.environ['XCAL_NO_M0_STI_TRIM'] = 'on'
        os.environ['PEX_FS_THREAD'] = '6'

        machines = ['hp20','ocean022','ocean023','ocean024','roll', 'mosa', 'davi']
        subprocess.call('xcalibrate -exec -xact3d -remote ' + random.choice( machines ) + ' ' + mipt + '>& xcalibrate.log', shell=True)
        subprocess.call('cat rules.FS rules.xact > rules', shell=True)

        os.chdir( qaobj.qa_path )
        print 'At',qaobj.qa_path, 'qa_func'
        subprocess.call('cp /home/rhuang/git/utility/autotune/example_qa/N7_v0d1_core_small_20151117_run ./ -R', shell=True)
        subprocess.call('cp /home/rhuang/git/utility/autotune/example_qa/n7_v0.1_pode_stdcell_fullMD_SCLD_A2_run ./ -R', shell=True)
        # subprocess.call('Arcx -p arcx.cfg -c 709 -O Q_EFFRES NO -nt 8 >& arcx.log', shell=True)
        # os.chdir('N7_v0d1_core_small_20151117_run')
        # subprocess.call('./run_csh_sge >& mylog.sge', shell=True)
        # os.chdir('../')
        return 0

    configObj.run_test = run_func
    #configObj.run_test = run_xcalibrate

    # configObj.calibration_script = r'''
    #     #!/bin/csh -f
    #     setenv XCAL_FINFET_CAL_DIR "/mtr_n7/mtr7_73861/PE003050/from_TSMC/0412_v0.5_qc_update_io_sampts"
    #     setenv XCAL_INTRINSIC_SUBTRACT_ALL on
    #     setenv XCAL_DISABLE_ENCRYPT on
    #     setenv PEX_FS_THREAD 6
    #     setenv XCAL_NO_M0_STI_TRIM on

    #     set MACHINEIDX = `perl -e 'srand;print int(rand(12)+1)'`
    #     xcalibrate -exec -xact3d -remote mtr7_$MACHINEIDX adari.mipt >& log.xcalibrate

    #     cat rules.FS rules.xact > rules
    #     rm calibration.db
    #     rm -rf models process mtr7*.log
    # '''


    # configObj.qa_script = r'''
    #     #!/bin/csh -f
    #     Arcx -p arcx.cfg -c 709 -O Q_EFFRES NO -nt 8 >& arcx.log

    #     cd N7_v0d1_core_small_20151117_run
    #     ./run_csh_sge >& mylog.sge
    #     cd ../

    #     # ./run_csh_sge >& log.sge

    #     find . -maxdepth 5 -name svdb | xargs rm -rf
    # ''' 

    # tunningMode = explore_QA
    configObj.rsd_db_1  = "./p_gpoly_io_svt.db"
    #configObj.rsd_db_2  = ""
    configObj.rsd_db_2  = "./n_gpoly_io_svt.db"
    configObj.assignment  = [                                                                                                  
                     ( 'p_gpoly_io_lvt.rsd_enclosure'    ,  'p_gpoly_io_svt.rsd_enclosure'    ), 
                     ( 'p_gpoly_io_lvt.rsd_spacing'      ,  'p_gpoly_io_svt.rsd_spacing'      ),
                     ( 'p_gpoly_io_lvt.rsd_thickness'    ,  'p_gpoly_io_svt.rsd_thickness'),
                     ( 'n_gpoly_io_lvt.rsd_enclosure'    ,  'n_gpoly_io_svt.rsd_enclosure'    ),
                     ( 'n_gpoly_io_lvt.rsd_spacing'      ,  'n_gpoly_io_svt.rsd_spacing'      ),
                     ( 'n_gpoly_io_lvt.rsd_thickness'    ,  'n_gpoly_io_svt.rsd_thickness')
                   ]

    # tunningMode = user
    configObj.exp_names  = [                                'g736b1',   'g736b2',    'g736b3',   'g736b4',     'g736b5'        ]
    configObj.exp_props  = [                                                                                                  
                     [ 'p_gpoly_lvt.rsd_enclosure'    ,     -0.003   ,  -0.003   ,   -0.003   ,   -0.003   ,   -0.003         ],                            
                     [ 'p_gpoly_lvt.rsd_spacing'      ,      0.0097  ,   0.0097  ,    0.0097  ,    0.0097  ,    0.0097        ],
                     [ 'p_gpoly_lvt.rsd_bot_thickness',      0.00081 ,   0.00082 ,    0.00083 ,    0.00084 ,    0.00085       ],
                     [ 'n_gpoly_lvt.rsd_enclosure'    ,      -0.003  ,   -0.003  ,    -0.003  ,    -0.003  ,    -0.003        ],
                     [ 'n_gpoly_lvt.rsd_spacing'      ,      0.0097  ,   0.0097  ,    0.0097  ,    0.0097  ,    0.0097        ],
                     [ 'n_gpoly_lvt.rsd_bot_thickness',      0.0005  ,   0.0005  ,    0.0005  ,    0.0005  ,    0.0005        ],
                     ( 'p_gpoly_svt.rsd_enclosure'    ,  'p_gpoly_lvt.rsd_enclosure'    ), 
                     ( 'p_gpoly_svt.rsd_spacing'      ,  'p_gpoly_lvt.rsd_spacing'      ),
                     ( 'p_gpoly_svt.rsd_bot_thickness',  'p_gpoly_lvt.rsd_bot_thickness'),
                     ( 'n_gpoly_svt.rsd_enclosure'    ,  'n_gpoly_lvt.rsd_enclosure'    ),
                     ( 'n_gpoly_svt.rsd_spacing'      ,  'n_gpoly_lvt.rsd_spacing'      ),
                     ( 'n_gpoly_svt.rsd_bot_thickness',  'n_gpoly_lvt.rsd_bot_thickness')
                   ]


    #---
    #  To define the config setting. Format: 
    #
    #      prop_name ,  ragne_start , range_end , scale_factor
    #
                     
    configObj.ga_pool_size           = 4
    configObj.ga_mutation_ratio      = 0.1
    configObj.ga_mutation_bits_ratio = 0.8

    def ga_fit_script( *args ): 
        qaobj, = args
        qapath = os.path.expanduser(qaobj.qa_path)
        calpath = os.path.expanduser(qaobj.cal_path)
        rulepath = os.path.join(calpath, 'rules.FS')
        nlvt_corr_gd = scaleVec( scan_lifringe4_first_line (rulepath,"LIFRINGE4","n_gpoly_lvt") , 1000)
        plvt_corr_gd = scaleVec( scan_lifringe4_first_line (rulepath,"LIFRINGE4","p_gpoly_lvt") , 1000)
        
        print "plvt lifringe4: " + str(plvt_corr_gd)
        print "nlvt lifringe4: " + str(nlvt_corr_gd)

        scoreN = distTo0(nlvt_corr_gd) 
        scoreP = distTo0(plvt_corr_gd)

        qaobj.reportDB['nlvt_lifringe4'] = scoreN
        qaobj.reportDB['plvt_lifringe4'] = scoreP

        qaItemReport = QAItemReport (qaobj.name, qapath + "/N7_v0d1_core_small_20151117_run")
        ccdist = qaItemReport.get_dist('cc')['stdev']
        print "ccdist: " + str(ccdist)
        qaobj.reportDB.update( qaItemReport.reportDB['cc'] )

        qaItemReport2 = QAItemReport (qaobj.name, qapath + "/n7_v0.1_pode_stdcell_fullMD_SCLD_A2_run")
        spdist = qaItemReport2.get_dist('sp')['stdev']
        print "spdist: " + str(ccdist)
        qaobj.reportDB.update( qaItemReport2.reportDB['sp'] )



        # #--- error handling
        # if ccdist == None:
        #     ccdist = 1000000

        # return 200.0 / (scoreN + scoreP + ccdist)
        return 200.0 / (scoreN + scoreP)

      
    def ga_stop_script( gaobj ):
        if gaobj.iteration > 3:
            return True
        else: 
            return False
      
    configObj.ga_fit_script = ga_fit_script
    configObj.ga_stop_script = ga_stop_script


    configObj.ga_constraints = [
                       ['p_gpoly_lvt.rsd_enclosure' ,           -0.010  , 0      ,  10000 , -0.0048    ],   
                       ['p_gpoly_lvt.rsd_spacing'   ,           0.005   , 0.013  ,  10000 , 0.0099     ],
                       ['POD.zbottom'               ,           0.070   , 0.085  ,  10000 , 0.077      ],
                       ['n_gpoly_lvt.rsd_enclosure' ,           -0.010  , 0      ,  10000 , -0.0024    ],   
                       ['n_gpoly_lvt.rsd_spacing'   ,           0.005   , 0.013  ,  10000 , 0.0097     ],
                       ['NOD.zbottom'               ,           0.070   , 0.085  ,  10000 , 0.077      ],

                       ('p_gpoly_svt.rsd_enclosure', ' p_gpoly_lvt.rsd_enclosure      '),   
                       ('p_gpoly_svt.rsd_spacing',   ' p_gpoly_lvt.rsd_spacing        '),
                       ('n_gpoly_svt.rsd_enclosure', ' n_gpoly_lvt.rsd_enclosure      '),   
                       ('n_gpoly_svt.rsd_spacing',   ' n_gpoly_lvt.rsd_spacing        '),

                       ('p_gpoly_svt.rsd_thickness', ' 0.12 - 0.001 - POD.zbottom     '),   
                       ('n_gpoly_svt.rsd_thickness', ' 0.12 - 0.001 - NOD.zbottom     '),   
                       ('p_gpoly_lvt.rsd_thickness', ' 0.12 - 0.001 - POD.zbottom     '),   
                       ('n_gpoly_lvt.rsd_thickness', ' 0.12 - 0.001 - NOD.zbottom     '),   
                       ('POD.rsd_thickness',         ' 0.12 - 0.001 - POD.zbottom     '),
                       ('NOD.rsd_thickness',         ' 0.12 - 0.001 - NOD.zbottom     ')
                    ]

    print 'Finished loading config'

    
    configObj.rsd_explore_constraint = [
                # seed_layer.prop                  tuning_unit   deltarange   mode (1: only run given range with fix tuning_unit 
                                                                                    #      2: fix tuning_unit recursive until meet cost funciton threshold
                                                                                    #      3: sort mode
                # rsd_* +tuning_unit*delta
                ['p_gpoly_svt.rsd_thickness' ,           0.001  , 1    ,1    ],
                ['p_gpoly_svt.rsd_enclosure' ,           0.001  , 3     ,3    ],
                ['p_gpoly_svt.rsd_spacing'     ,         0.001  , 3     ,3    ],
                #['n_gpoly_svt.rsd_enclosure' ,           -0.010  , 0      ,  10000 , -0.0048    ],
                #['n_gpoly_svt.rsd_space'     ,           -0.010  , 0      ,  10000 , -0.0048    ],
                #['n_gpoly_svt.rsd_thickness' ,           -0.010  , 0      ,  10000 , -0.0048    ],
                ]




