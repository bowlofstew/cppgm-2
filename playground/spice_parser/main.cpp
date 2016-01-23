

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include <exception>
#include <map>
#include <limits>
#include <algorithm>
#include <cmath>
#include <cstdlib>

#include "subckt.h"

using namespace std;

template<class C>
std::string to_string(const C &input) {

    std::stringstream ss;
    ss << input;
    return ss.str();
}

inline char to_lower (const char c) 
{
    if (c >= 'A' && c <= 'Z' ) {
        char t = c - 'A' + 'a';
        return t;
    }
    return c;
}


inline bool isDigit (char c) {
    return (c >= '0' && c <= '9');
}


double to_double(const std::string& input ) {

    stringstream ss;
    int state = 0;
    unsigned idx = 0;
    double scale = 1;
    while (idx < input.size()) {
        char c = to_lower( input[idx] );

        switch (state) {
            case 0:
                if ( isDigit(c) ) {
                    ss << c;
                    state = 1;
                } else if ( c == '-') {
                    ss << c;
                    state = 1;
                } else {
                    state = -1;
                }
                break;
            case 1:
                if ( isDigit(c) ) {
                    ss << c;
                } else if ( c == '.' ) {
                    ss << c;
                    state = 2;
                } else if ( c == 'e' ) {
                    ss << c;
                    state = 3;
                } else {
                    state = -1;
                }
                break;
            case 2:
                if ( isDigit(c) ) {
                    ss << c;
                    state = 20;
                } else {
                    state = -1;
                }
                break;
            case 20:
                if (isDigit(c) ) {
                    ss << c;
                } else if (c == 'e' ) {
                    ss << c;
                    state = 3;
                }
                else {
                    state = -1;
                }
                break;
            case 3:
                if ( c == '+' || c == '-' ) {
                    ss << c;
                    state = 30;
                } else if ( isDigit(c) ) {
                    ss << c;
                    state = 30;
                } else {
                    state = -1;
                }
                break;
            case 30:
                if ( isDigit(c) ) {
                    ss << c;
                } else {
                    state = -1;
                }
                break;

            case -1:
                break;

            default:
                state = -1;
                break;
        }         

        if (state == -1) {
            break;
        }

        idx++;
    } // end of while

    string num = (idx>=1) ? input.substr(0,idx) : "" ;
    string suffix = input.substr(idx, input.size() - idx );

    if ( num == "") {
        stringstream sse;
        sse << "ERROR: while converting number : " << input;
        throw SpiceParserException ( sse.str().c_str()  );
    }

    double ret = atof(num.c_str());
    if (suffix.size() > 0) {
        if (iequal ( suffix, "f") || iequal (suffix, "ff")) {
            ret *= 1e-15;
        }
        else if (iequal ( suffix, "p") || iequal (suffix, "pf")) {
            ret *= 1e-12;
        }
        else if (iequal( suffix, "k")) {
            ret *= 1000;       
        }
        else if (iequal( suffix, "m")) {
            ret *= 1e6;
        }
        else {
            stringstream sse;
            sse << "ERROR: while converting number : " << input;
            throw SpiceParserException ( sse.str().c_str()  );
        }
    }
    return ret;
}


void helpMsg() {
    cout << "Usage:" << endl;
    cout << "  spice_parser <spiceFile> [options...] " << endl;
    cout << "    options includes: " << endl;
    cout << "      -cc " << endl;
    cout << "      -tc " << endl;
    cout << "      -ccall " << endl;
    cout << "      -conly <filename>" << endl;
    cout << "      -ronly <filename>" << endl;
    cout << "      -svs <filename>" << endl;
    cout << "      -debug" << endl;
}


class SpicePreprocessor : public TxtPreprocessor {
  public:
    SpicePreprocessor() {}
    ~SpicePreprocessor() {}

    bool isCommentStart(char c) {
        if (c == '*')
            return true;
        else
            return false;
    }

    bool isSingalCharOp( char c ) {
        if ( c == '=' || c == '+' )
            return true;
        else
            return false;
    }

    //---
    // a state machine to get id/number/string/operator/lineend token
    //
    virtual std::vector<PPToken> tokenize (const std::string& inStr) {
        int line = 1;
        int state = 0;
        int idx = 0; 
        std::string t = "";
        
        std::vector<PPToken> myTokens;

        while (idx < inStr.size()) {
            char c = inStr[idx];

            switch (state) 
            {
                case 0:
                    if ( isChar(c) || isDigit(c) || c=='_' || c=='.' || c == '$' || c== '-' ) {
                        state = 1;
                        t = c;
                    }
                    else if (isSpace(c)) {
                        t = c;
                        myTokens.push_back( makeToken ( t, PP_SPACE, line ) );
                        t = "";
                        state = 0;
                    }
                    else if (isLineEnd(c)) {
                        state = 0;
                        myTokens.push_back( makeToken ( "\n", PP_LE, line ) );
                        line++;
                    } 
                    else if (isCommentStart(c)) {
                        state = 2; 
                    } 
                    else if (isSingalCharOp(c)) {
                        t = c;
                        myTokens.push_back( makeToken ( t, PP_OP, line ) );
                        t = "";
                        state = 0;
                    }
                    else {
                        std::stringstream ss;
                        ss << "Bad token start char " << "\'" << c << "\' at line " << line;
                        throw_pprop_exp( ss.str() );
                    }
                    break;
                case 1:
                    if ( c != '=' && !isSpace(c) && !isLineEnd(c) ) {
                        state = 1;
                        t += c;
                    }
                    else {
                        state = 0;
                        myTokens.push_back( makeToken(t, PP_ID, line ) );
                        t = "";
                        idx--;
                    }
                    break;
                case 2:
                    while (idx < inStr.size()) {
                        if (inStr[idx] == '\n') {
                            myTokens.push_back( makeToken("\n", PP_LE, line ));
                            line++;
                            t = "";
                            state = 0;
                            break;
                        }                  
                        idx++;
                    } 
                    break;
                default:
                    std::stringstream ss;
                    ss << "Bad token state around line " << line;
                    throw_pprop_exp( ss.str() );
                    break;
            }
            
            idx++;
        }

        return myTokens;
    }


    // reuse the default postProcess code from "TxtPreprocessor"
    // but skip all spaces
    // 
    void postProcess() 
    {
        std::vector<PPToken> tmpTokens; 

        std::vector<PPToken>::iterator  it; 
        for (it = tokens.begin(); it != tokens.end(); it++) 
        {
             if (it->type == PP_SPACE) {
                 ; // do nothing 
             }
             else if ( it->str == "+" ) {
                if (tmpTokens.back().type == PP_LE) {
                    tmpTokens.pop_back();
                }
             }
             else 
             {
                tmpTokens.push_back( *it );
             }
         }
         tokens = tmpTokens; 
     }

};



//------- class SubcktNet {
//
SubcktNet::SubcktNet ( const string& name ) 
    : _name(name) , _id(0) , _cPin(0), _cPort(0) 
{
}

SubcktNet::~SubcktNet() {
}

void SubcktNet::connect( SubcktInst* inst ) {
    _insts.push_back( inst );
    if (inst->_cell->_type == Subckt::USER) {
        _cPin += 1;
    }
}

const string& SubcktNet::to_string() {
    return _name;
}

bool compare_subckNet_pointer (SubcktNet* p1, SubcktNet* p2) {
    int score1 = 0;
    int score2 = 0;

    if (p1->_cPort > p2->_cPort) {
        return true;
    } 
    else if ( p1->_cPort < p2->_cPort ) {
        return false;
    }
    else {
        if ( p1->_cPin > 0 && p2->_cPin == 0 ) {
            return true;
        }
        else if ( p1->_cPin == 0 && p2->_cPin > 0 ) {
            return false;
        }
        else {  // both connected to instance, or neither connected to instances
            return (p1->_name > p2->_name);
        }
    }
}



//---- class SubcktInst 
//
SubcktInst::SubcktInst ( Subckt* pparent, Subckt* pcell, const string& name ) 
    : _parent(pparent), _cell(pcell), _name(name), _value(0) 
{
}

SubcktNet* SubcktInst::connect ( SubcktNet* n1) {
    _pins.push_back(n1);
    n1->connect( this );
}

SubcktNet* SubcktInst::connect ( SubcktNet* n1, SubcktNet* n2) {
    connect( n1 );
    connect( n2 );
}



string SubcktInst::to_string() 
{
    stringstream ss;
    ss << _name << " ";
    for ( unsigned i=0; i<_pins.size(); ++i) 
    {
        ss << _pins[i]->to_string() << " ";
    }

    if ( _cell->_type == Subckt::USER) {
        ss << _cell->_name << " ";
        ss << _prop;
    }
    else {
        ss << _value;
    }
    return ss.str();
}


//---- class Subckt 

Subckt::Subckt ( const string& name ) 
    : _name(name), _idCount(0), _referenceCount(0)  
{
}

Subckt::~Subckt() {
    for ( map<string,SubcktInst*>::iterator it = _instMap.begin(); it != _instMap.end(); ++it) {
        delete it->second;
    }

    for ( map<string,SubcktNet*>::iterator it2 = _netMap.begin(); it2 != _netMap.end(); ++it2) {
        delete it2->second;
    }
}


SubcktNet* Subckt::create_port ( const string& portName ) {
    SubcktNet* pnet = make_net ( portName );
    _portMap[ portName ] = pnet;
    _ports.push_back( pnet );
    _netMap[ portName ] =  pnet;
    pnet->_cPort += 1;
    return pnet;
}


// 1. the pins must be in port declaration order
// 2. Did not check it the 
//
SubcktInst* Subckt::make_inst ( Subckt* cell, const string& name, const vector<string>& pins ) {
    if (cell->_type == Subckt::RES) {
        stringstream ss;
        ss << "ERROR: creating instance " << name << " with resistance cell"; 
        throw SpiceParserException(ss.str().c_str()); 
    }
    if (_instMap.find(name) != _instMap.end()) {
        stringstream ss;
        ss << "ERROR: duplicate instance creation " << name ; 
        throw SpiceParserException(ss.str().c_str()); 
    }
    //-- keep minimum hierarchy information
    //
    this->_childCellMap[cell->_name] = cell;
    cell->_referenceCount++;

    SubcktInst* pinst = new SubcktInst( this, cell, name );
    _instMap[name] = pinst;
    _insts.push_back( pinst );
    for (unsigned i=0; i< pins.size(); i++) {
        SubcktNet* pnet = make_net( pins[i] );
        pinst->connect (pnet);
    }
    return pinst;
}


//--- Special handling for cap and res devices.
//    Propagate netid information from one net to the other if they are
//    connected by resistor. If both nets have netid, we need to merge them.
//
SubcktInst* Subckt::make_dual_port_inst (Subckt* cell, const string& name, const string& n1, const string& n2) 
{
    if (_instMap.find(name) != _instMap.end()) {
        stringstream ss;
        ss << "ERROR: duplicate instance creation " << name ; 
        throw SpiceParserException(ss.str().c_str()); 
    }

    SubcktInst* pinst = new SubcktInst( this, cell, name );
    cell->_referenceCount++;
    map<string,SubcktNet*>::iterator it1 = _netMap.find( n1 );
    map<string,SubcktNet*>::iterator it2 = _netMap.find( n2 );
    SubcktNet* pnet1 = NULL;
    SubcktNet* pnet2 = NULL;

    //-- two nets sharing the same net object
    //
    if (it1 == _netMap.end() && it2 == _netMap.end() ) {
        SubcktNet* pnet1 = new SubcktNet( n1 );
        SubcktNet* pnet2 = new SubcktNet( n2 );
        _netMap[n1] = pnet1;
        _netMap[n2] = pnet2;
        pinst->connect( pnet1, pnet2);

        if (cell->_type == Subckt::RES) {
            make_id( pnet1 );
            assign_id ( pnet1, pnet2 );
        } else {
            // cap
            make_id( pnet1 );
            make_id( pnet2 );  
        }
    }
    else if (it1 != _netMap.end() && it2 == _netMap.end() ) {
        SubcktNet* pnet1 = it1->second;
        SubcktNet* pnet2 = new SubcktNet( n2 );
        _netMap[n2] = pnet2;
        pinst->connect( pnet1, pnet2);

        if (cell->_type == Subckt::RES) {
            assign_id( pnet1, pnet2 );
        } else {
            // cap
            make_id( pnet2 );
        }
    }
    else if (it1 == _netMap.end() && it2 != _netMap.end() ) {
        SubcktNet* pnet1 = new SubcktNet( n1 );
        SubcktNet* pnet2 = it2->second;
        _netMap[n1] = pnet1;
        pinst->connect( pnet1, pnet2);

        if (cell->_type == Subckt::RES) {
            assign_id( pnet2, pnet1 );
        } else {
            // cap
            make_id( pnet1 );
        }
    }
    else {
        SubcktNet* pnet1 = it1->second;
        SubcktNet* pnet2 = it2->second;
        pinst->connect( pnet1, pnet2);

        if (cell->_type == Subckt::RES) {
            merge_id (pnet1, pnet2);
        }
    }

    _instMap[name] = pinst;
    _insts.push_back( pinst );
    return pinst;
}


SubcktNet* Subckt::make_net (const string& name, SubcktNetGroupID id) {
    map<string,SubcktNet*>::iterator it = _netMap.find( name );

    if ( it == _netMap.end() ) {
        SubcktNet* pnet = new SubcktNet( name );

        if (id == 0) { 
            make_id( pnet );
        } else {
            pnet->_id = id;
        }

        _netMap[name] = pnet;
        return pnet;
    } 
    else  {
        return it->second;
    }
}


//--- Keep a ID in each net. The id is a pointer
//    _idNetMap to keep the nets that belong to the same net id
//
void Subckt::make_id ( SubcktNet* pnet ) {
    SubcktNetGroupID id = ++_idCount;
    pnet->_id = id;
    _idList.push_back(id);
    _idNetMap[id].push_back(pnet);  
}


void Subckt::assign_id ( SubcktNet* src, SubcktNet* tar ) {
    tar->_id = src->_id;
    _idNetMap[src->_id].push_back( tar );
}


void Subckt::merge_id ( SubcktNet* net1, SubcktNet* net2) {

    if (net1->_id == net2->_id) {
        return;
    }

    unsigned size1 = _idNetMap[net1->_id].size();
    unsigned size2 = _idNetMap[net2->_id].size();
    SubcktNetGroupID id1 = net1->_id; 
    SubcktNetGroupID id2 = net2->_id;
    // cout << "Merging: " << net1->_name << " " << net1->_id <<  " --- " << net2->_name << " " << net2->_id << endl;

    if (size1 >= size2) {
        for (unsigned j=0; j < size2; j++) {
            _idNetMap[id2][j]->_id = id1;

            // cout << "  assign " << id1 << " to " << _idNetMap[id2][j]->_name << endl;
        }
        _idNetMap[id1].insert( _idNetMap[id1].end(), _idNetMap[id2].begin(), _idNetMap[id2].end()); 
        _idNetMap[id2].clear();
    } 
    else {
        for (unsigned j=0; j < size1; j++) {
            _idNetMap[id1][j]->_id = id2;

            // cout << "  assign " << id2 << " to " << _idNetMap[id1][j]->_name << endl;
        }
        _idNetMap[id2].insert( _idNetMap[id2].end(), _idNetMap[id1].begin(), _idNetMap[id1].end()); 
        _idNetMap[id1].clear();
    }
}


string Subckt::to_string()
{
    stringstream ss;
    ss << ".subckt " << _name << " ";
    for (unsigned i=0; i<_ports.size(); ++i) {
        ss << _ports[i]->to_string() << " ";
    }
    ss << endl;

    for (unsigned j=0; j<_insts.size(); ++j) {
        ss << _insts[j]->to_string() << endl;
    }
    
    ss << ".ends" << endl; 

    return ss.str();
}


string Subckt::to_string_conly( )
{
    Subckt* p = this;
    stringstream conlyfs; 
    conlyfs << ".subckt " << p->_name << " ";

    map<SubcktNetGroupID,string> idNameMap;

    for (unsigned i=0; i< p->_ports.size(); ++i) {
        conlyfs << p->_ports[i]->_name << " "; 
        idNameMap[ p->_ports[i]->_id ] = p->_ports[i]->_name;
    }
    conlyfs << endl;

    vector<SubcktInst*>::iterator iit = p->_insts.begin();
    for (; iit != p->_insts.end(); ++iit)
    {
        SubcktInst* pinst = *iit;
        if (pinst->_cell->_type == Subckt::RES) 
        {
            continue;
        }
        conlyfs << pinst->_name << " ";
        for (unsigned j=0; j<pinst->_pins.size(); j++) {
            SubcktNet* pnet = pinst->_pins[j];

            map<SubcktNetGroupID,string>::iterator mit = idNameMap.find( pnet->_id );
            if ( mit != idNameMap.end() ) {
                conlyfs << mit->second << " ";
            }
            else {
                conlyfs << "imd" << pnet->_id << " ";
            }
        }

        if (pinst->_cell->_type == Subckt::CAP) {
            conlyfs << pinst->_value << endl;
        } 
        else  // user defined instace 
        {
            conlyfs << pinst->_cell->_name << " ";
            conlyfs << pinst->_prop << endl;
        }
    }
    conlyfs << ".ends" << endl;
    return conlyfs.str();
}


string Subckt::to_string_ronly() 
{
    Subckt* p = this;
    stringstream ronlyfs; 
    ronlyfs << ".subckt " << p->_name << " ";
    for (unsigned i=0; i< p->_ports.size(); ++i) {
        ronlyfs << p->_ports[i]->_name << " "; 
    }
    ronlyfs << endl;

    vector<SubcktInst*>::iterator iit = p->_insts.begin();
    for (; iit != p->_insts.end(); ++iit)
    {
        SubcktInst* pinst = *iit;
        if (pinst->_cell->_type == Subckt::CAP) 
        {
            continue;
        }
        ronlyfs << pinst->_name << " ";

        for (unsigned j=0; j<pinst->_pins.size(); j++) {
            ronlyfs << pinst->_pins[j]->_name << " ";
        }

        if (pinst->_cell->_type == Subckt::RES) {
            ronlyfs << pinst->_value << endl;
        } 
        else  // user defined instace 
        {
            ronlyfs << pinst->_cell->_name << " ";
            ronlyfs << pinst->_prop << endl;
        }
    }
    ronlyfs << ".ends" << endl;
    return ronlyfs.str();

}


string Subckt::to_string_norc ()
{
    Subckt* p = this;
    stringstream norcfs; 
    norcfs << ".subckt " << p->_name << " ";

    for (unsigned i=0; i< p->_ports.size(); ++i) {
        norcfs << p->_ports[i]->_name << " "; 
    }
    norcfs << endl;

    vector<SubcktInst*>::iterator iit = p->_insts.begin();
    for (; iit != p->_insts.end(); ++iit)
    {
        SubcktInst* pinst = *iit;
        if (pinst->_cell->_type == Subckt::RES || pinst->_cell->_type == Subckt::CAP) 
        {
            continue;
        }
        norcfs << pinst->_name << " ";
        for (unsigned j=0; j<pinst->_pins.size(); j++) {
            SubcktNet* pnet = pinst->_pins[j];
            if (pnet->_cPort > 0) {
                norcfs << pnet->_name << " ";
            } else {
                norcfs << "imd" << pnet->_id << " ";
            }
        }
        norcfs << pinst->_cell->_name << " ";
        norcfs << pinst->_prop << endl;
    }
    norcfs << ".ends" << endl;
    return norcfs.str();
}


string Subckt::to_string_debug()
{
    stringstream ss;
    ss << ".subckt " << _name << " ";
    for (unsigned i=0; i<_ports.size(); ++i) {
        ss << _ports[i]->to_string() << " ";
    }
    ss << endl;

    unsigned netCount = 0;
    map<SubcktNetGroupID, vector<SubcktNet*> >::iterator mit = _idNetMap.begin();
    for ( ; mit != _idNetMap.end(); ++mit) {
        if (mit->second.size() > 0) {
            netCount++;
            ss << "    [" << mit->first << "] " << endl;
            for (unsigned i=0; i<mit->second.size(); i++) {
                ss << "        " << mit->second[i]->_name << endl;
            }
        }
    } 
   
    unsigned instCount = 0;
    map<string,SubcktInst*>::iterator mit2 = _instMap.begin();
    for ( ; mit2 != _instMap.end(); ++mit2) {
        if (mit2->second->_cell->_type == Subckt::USER) {
            instCount++;
            ss << "    [" << mit2->first << "] " << endl;
            for (unsigned i=0; i<mit2->second->_pins.size(); i++) 
            {
                SubcktNet* pn =  mit2->second->_pins[i];
                ss << "        " << pn->_name << "  " << pn->_id << endl;
            }
        }
    }
    ss << ".ends" << endl; 
    ss << netCount << " net id, " << instCount << " instances" << endl; 

    return ss.str();
}




//---- class SpiceDesign 
//
SpiceDesign::SpiceDesign ()
{
    //--- create predefined cells, cap and res
    //
    Subckt* pres = make_subckt ("resistor");
    pres->create_port("rp1");
    pres->create_port("rp2");
    pres->_type = Subckt::RES; // special handling for res

    Subckt* pcap = make_subckt ("capacitor");
    pcap->create_port("cp1");
    pcap->create_port("cp2");
    pcap->_type = Subckt::CAP; // speical handling for cap
}

SpiceDesign::~SpiceDesign () {
    for ( map<string,Subckt*>::iterator it = _subcktMap.begin(); it != _subcktMap.end(); ++it) {
        Subckt* p = it->second;
        delete p;
    } 
}

Subckt* SpiceDesign::make_subckt( const string &name ) 
{
    Subckt* psubckt = NULL;
    map<string,Subckt*>::iterator it = _subcktMap.find( name );

    if (it == _subcktMap.end()) {
        psubckt = new Subckt( name ); 
        psubckt->_type = Subckt::USER;
        _subcktMap[ name ] = psubckt;
        _subckts.push_back( psubckt );
    } 
    else {
        psubckt = it->second;
    }

    return psubckt;
}

void SpiceDesign::addTop( Subckt* top ) {
    _tops.push_back(top);
}

vector<Subckt*> SpiceDesign::getTops() {
    return _tops;
}


Subckt* SpiceDesign::getTop0() {
    return _tops[0];
}


string SpiceDesign::to_string() {
    stringstream ss;

    Subckt* p = _tops[0];

    //--- dump the leaf node first
    //
    list<Subckt*> stack;
    list<Subckt*> result;

    stack.push_back( p );
    while (stack.size() != 0) {
        Subckt* pc = stack.front();
        stack.pop_front();
        result.push_front( pc );

        map<string,Subckt*>::iterator mit = pc->_childCellMap.begin();
        for (; mit != pc->_childCellMap.end(); ++mit) {
            stack.push_front( mit->second );
        }
    }

    for (list<Subckt*>::iterator lit = result.begin(); lit != result.end(); lit++) {
        Subckt* p = *lit;
        if (p->_type == Subckt::USER) 
        {
            ss << p->to_string() ;
            ss << endl;
        }
    }

    return ss.str();
}


string SpiceDesign::to_string_norc() {
    stringstream ss;

    for (unsigned i=0; i<_subckts.size(); i++) {
        if (_subckts[i]->_type == Subckt::USER) 
        {
            ss << _subckts[i]->to_string_norc() ;
            ss << endl;
        }
    }

    return ss.str();
}




class SpiceParser : public TxtParser {
  public:
    SpiceParser( string filename )
        :  _sp_prop(0)
    {
        ostringstream buffer; 
        ifstream spfile(filename.c_str(), std::ifstream::in);   
        buffer << spfile.rdbuf();

        string inStr = buffer.str();
        SpicePreprocessor* _sp_prop = new SpicePreprocessor();
        _sp_prop->process( inStr );

        // debug
        // _sp_prop->dumpTokens();

        cit = _sp_prop->tokens.begin();
        eit = _sp_prop->tokens.end();
        // _fsMgr.dump();

    }

    ~SpiceParser() {
        delete _sp_prop;
    }

   
    void parse_subckt () {
        match(".subckt");
        PPToken tname = match(PP_ID);

        _pSubckt = _design.make_subckt( tname.str );

        //--- get ports
        //
        while (cit->type != PP_LE) {
            PPToken t_port = match (PP_ID);
            _pSubckt->create_port( t_port.str );
        }

        while ( true ) {
            if ( cit->type == PP_ID ) {
                if ( iequal(cit->str, ".ends")) {
                    break;
                } else {
                    parse_inst();
                }
            }
            else if (cit->type == PP_LE) {
                match (PP_LE);
            } else {
                throw_error_at_current_token("Unexpected line start type, should be Res, Cap, or user-defined type");
            }
        }
        match(".ends");
    }


    void parse_inst () {
        PPToken t_name = match ( PP_ID );
        Subckt* pcell = NULL;
        char ctype = to_lower ( t_name.str[0] );
        SubcktInst* pinst = NULL;

        // 'v' is a special component from QC, we take it as resistor
        //
        if ( ctype != 'r' && ctype != 'c'  && ctype != 'v' ) {
            // 
            // General user defined cell,
            // find cell, if not found, make one. 
            //
            string modelName = "";
            vector<string> pins;

            while ( cit->type != PP_LE ) {
                if (cit->type == PP_ID ) {
                    PPToken t = match(PP_ID);
                    pins.push_back( t.str );
                }
                else if (cit->str == "=" )
                {
                    modelName = pins[ pins.size()-2 ];
                    pins.pop_back();
                    pins.pop_back();
                    rollback(); //-- move cit to first property name
              
                    // -- create cell and cell ports
                    //
                    pcell = _design.make_subckt ( modelName );
                    if (pcell->_portMap.size() == 0) {
                        for (unsigned i=0; i<pins.size(); i++) {
                            stringstream pss;
                            pss << "p" << i+1;
                            pcell->create_port( pss.str() );
                        }
                    }
                    break;
                }
            }
            pinst = _pSubckt->make_inst ( pcell, t_name.str, pins) ;
        }
        else   // otherise, special handle two-ports res/cap 
        {
            if (ctype == 'r' || ctype == 'v' ) 
            {
                pcell = _design.make_subckt ( "resistor" );
            } 
            else // 'c'
            {
                pcell = _design.make_subckt ( "capacitor" );
            }
            PPToken t_net1 = match ( PP_ID );
            PPToken t_net2 = match ( PP_ID );
            PPToken t_value = match ( PP_ID );
            pinst =  _pSubckt->make_dual_port_inst (pcell, t_name.str, t_net1.str, t_net2.str ); 

            double value = to_double ( t_value.str );
            pinst->_value = value;
        }

        //--- collect properties
        //
        stringstream ss;
        while (cit->type != PP_LE) {
            PPToken pname = match(PP_ID);
            match("=");
            PPToken pval  = match(PP_ID);
            ss << pname.str << "=" << pval.str << " ";
        }
        pinst->_prop  = ss.str();
    }


    void parse() {
        while ( cit != eit ) {
            if ( cit->type == PP_ID) {
                if ( iequal(cit->str, ".END")) {
                    break;
                }
                parse_subckt ();
            } 
            else if ( cit->type == PP_SPACE || cit->type == PP_LE ) {
                cit++;
            }
            else {
                throw_error_at_current_token("Unexpected line start token");
            }
        }
        //--- checking 1
        for (map<string,Subckt*>::iterator it = _design._subcktMap.begin(); it != _design._subcktMap.end(); ++it)
        {
            Subckt* ps = it->second;
            if ( ps->_referenceCount == 0 ) {
                if (ps->_type == Subckt::USER) {
                    _design.addTop( it->second );
                }
            }
        }
        //--- checking 2
        if (_design.getTops().size() > 1) {
            throw SpiceParserException("ERROR: More than 1 top cell");
        }
        //--- post process 3
        Subckt *p = _design.getTop0();
        map< SubcktNetGroupID, vector<SubcktNet*> >::iterator it = p->_idNetMap.begin();
        for (; it != p->_idNetMap.end(); ++it) 
        {
            // sort vector SubcktNet* pointer in _idNetMap
            std::sort( it->second.begin(), it->second.end(), compare_subckNet_pointer);
        }
    }

    SpiceDesign& getDesign() {
        return _design;
    }


    void throw_error_at_current_token ( string prefix_msg ) {
        stringstream ss;
        ss << prefix_msg << " : \"";
        ss << cit->str << "\" at line " << cit->line;
        throw SpiceParserException(ss.str().c_str());
    }

    void throw_warning_at_current_token ( string prefix_msg ) {
        stringstream ss;
        ss << "WARNING: ";
        ss << prefix_msg << " : \"";
        ss << cit->str << "\" at line " << cit->line;

        cout << ss.str();
    }


  private:
    SpicePreprocessor *_sp_prop;
    SpiceDesign       _design;
    Subckt*           _pSubckt;  // current subckt

};


bool is_end_with(const string& s, const string& sub) {
    if (sub.length() > s.length()) {
        return false;
    } else {
        return (0 == s.compare(s.length() - sub.length(), sub.length(), sub));
    }
}

class DotGen 
{
  public:
    DotGen (Subckt* p ) {
        _p = p;
    }

    void gen ( string netName ) {
        stringstream ss0;
        ss0 << genHeader(); 

        SubcktNet* pnet = _p->_netMap[ netName ];
        vector<SubcktNet*> &allNets = _p->_idNetMap[ pnet->_id ];

        map<SubcktInst*, SubcktInst*> checkedInstMap;
        for ( unsigned i=0; i<allNets.size(); i++ ) 
        {
            SubcktNet* cnet = allNets[i];
            for (unsigned j=0; j< cnet->_insts.size(); j++) 
            {
                SubcktInst* cinst = cnet->_insts[j];

                if ( cinst->_cell->_type == Subckt::RES && 
                     checkedInstMap.find( cinst ) == checkedInstMap.end())  
                {
                    ss0 << "    \"" << cinst->_pins[0]->_name << "\" -- \"" << cinst->_pins[1]->_name << "\"";
                    ss0 << " [label=\""  << cinst->_value << "\"]" << endl;
                    checkedInstMap[ cinst ] =  cinst;
                }
            }
        }
        ss0 << "}";

        stringstream ssname;
        ssname << netName << ".dot";

        ofstream ofs( ssname.str().c_str() );
        ofs << ss0.str() << endl;
        ofs.close();
    }


    string genHeader ( ) {
        stringstream ss;
        ss << "graph graf {" << endl
           << "    orientation = portrait" << endl
           << "    size=\"10,8\"" << endl
           << "    margin = 0.25" << endl
           << "    fontsize = 8" << endl
           << "    overlap = scale" << endl
           << "    center = true" << endl
           << "    ranksep = 1.0" << endl
           << "    node [shape=ellipse]" << endl << endl;

        return ss.str();
    }

    Subckt* _p;
};


class P2pGen {
  public:
    P2pGen(Subckt* p) {
        _p = p;
    }

    void run_calcd ( string netName ) 
    {
        map<string,SubcktNet*>::iterator nit = _p->_netMap.find(netName);

        if ( nit == _p->_netMap.end()) {
            stringstream ss;
            ss << "ERROR: Cannot find net \"" << netName << "\"" << endl; 
            cout << ss.str();
            return;
        }
        else {

            //--- generate spef file for target net
            //
            stringstream ss0;
            SubcktNet* pnet = nit->second;
            vector<SubcktNet*> &allNets = _p->_idNetMap[ pnet->_id ];

            ss0 << "*D_NET " << netName << endl; 
            ss0 << "*PORTS" << endl;

            vector<string> pinNameList;
            vector<string> resistLine;

            map<SubcktInst*, SubcktInst*> checkedInstMap;
            for ( unsigned i=0; i<allNets.size(); i++ ) 
            {
                SubcktNet* cnet = allNets[i];
                if (cnet->_cPin > 0 || cnet->_cPort > 0) {
                    pinNameList.push_back( cnet->_name );
                }
                for (unsigned j=0; j< cnet->_insts.size(); j++) 
                {
                    SubcktInst* cinst = cnet->_insts[j];
                    if ( checkedInstMap.find( cinst ) != checkedInstMap.end()) {
                        continue;
                    } 
                    else {
                        //--- TODO:
                        //    treat Cap as 1/jwC 
                        //
                        if ( cinst->_cell->_type == Subckt::RES ) {
                            stringstream ssr;
                            ssr << cinst->_name << " " << cinst->_pins[0]->_name << " " << cinst->_pins[1]->_name << " ";
                            ssr << cinst->_value << endl;
                            checkedInstMap[ cinst ] =  cinst;
                            resistLine.push_back( ssr.str() );
                        }
                    }
                }
            }

            for (unsigned i=0; i< pinNameList.size(); i++) {
                ss0 << "*P " << pinNameList[i] << " O" << endl;
            }

            ss0 << "*RES" << endl;
            for (unsigned i=0; i<resistLine.size(); i++) {
                ss0 << resistLine[i] << endl;
            }
            ss0 << "*END";

            stringstream ssname;
            ssname << netName << ".spef";
            ofstream ofs( ssname.str().c_str() );
            ofs << ss0.str() << endl;
            ofs.close();

            //--- generate calcd control file 
            //
            stringstream ssname2; 
            ssname2 << netName << ".driver";
            ofstream ofs2( ssname2.str().c_str() );
            ofs2 << "D_NET " << netName << endl;
            for (unsigned i=0; i< pinNameList.size(); i++) {
                if (pinNameList[i] == netName) {
                    continue;
                }
                ofs2 << "test " << netName << "____" << pinNameList[i] << endl;
                ofs2 << "source " << pinNameList[i] << " 1" << endl;
                ofs2 << "sink " << netName << " 0" << endl;
                ofs2 << "end" << endl;
            }
            ofs2.close();

            //--- run calcd
            //
            stringstream ss3;
            ss3 << "$MGC_HOME/bin/calcd -p2p -control_file " << ssname2.str() << " -spef_file " << ssname.str();
            ss3 << " -output_file " << netName << ".calcd";
            int ret = system( ss3.str().c_str() );
            if (ret != 0) {
                cout << "Calcd p2p result " << ret << endl;
            }
        }
    }


    Subckt* _p;

};


class NetPair {
  public:
    NetPair( SubcktNetGroupID n1, SubcktNetGroupID n2) 
        : a(n1), b(n2) 
    {
    }
    SubcktNetGroupID a;
    SubcktNetGroupID b;
};


struct NetPairCompare {
    bool operator() (const NetPair& p1, const NetPair& p2) const {
        if ( p1.a > p2.a ) {
            return true;
        } else if (p1.a == p2.a) {
            if (p1.b > p2.b) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};


string to_string_svs ( const string& src, const string& tar ) {
    stringstream svs;
    svs << "SOURCE PRIMARY \"" << src  << "\"" << endl;
    svs << "SOURCE PATH \"src.spf\"" << endl;
    svs << "SOURCE SYSTEM SPICE" << endl;
    svs << "LAYOUT PRIMARY \"" << tar  << "\"" << endl;
    svs << "LAYOUT PATH \"tar.spf\"" << endl;
    svs << "LAYOUT SYSTEM SPICE" << endl;
    svs << "LVS REPORT \"lvs.rep\"" << endl;
    svs << "LVS REPORT MAXIMUM ALL" << endl;
    svs << "LVS FILTER R SHORT" << endl;
    svs << "LVS FILTER C OPEN" << endl;
    svs << "MASK SVDB DIRECTORY \"svdb\" IXF NXF QUERY" << endl;

    svs << "LVS NON USER NAME INSTANCE \".\"" << endl;
    svs << "LVS NON USER NAME NET \".\"" << endl;
    svs << "LVS SPICE STRICT WL YES" << endl;
    svs << "LVS RECOGNIZE GATES  NONE" << endl;
    svs << "LVS REDUCE PARALLEL MOS NO" << endl;
    svs << "LVS REDUCE SPLIT GATES NO" << endl;
    svs << "LVS ISOLATE SHORTS YES" << endl;
    svs << "LVS REPORT OPTION S" << endl;
    svs << "LVS SPICE SLASH IS SPACE NO" << endl;

    return svs.str();
}


int main(int argc, char* args[])
{
    if ( argc < 2 ) {
        helpMsg();
        return 1;
    }

    string outFile;
    string inFile;

    // default setting:
    //
    bool bCheckTc = false;
    bool bCheckTcAll = false;
    bool bCheckCcAll = false;
    bool bCheckCc = false;
    bool bRonly = false;
    bool bConly = false;
    bool bNorc = false;
    bool bSvs = false;
    bool bSync = false;
    bool bDebug = false;
    bool bDot = false;
    bool bP2p = false;
    string ronlyFile = "";
    string conlyFile = "";
    string norcFile = "";
    string svsFile = "";
    string syncFile = "";
    string dotNet = "";
    string p2pNet = "";


    //--- Command line arguments parsing
    //
    for (int i=1 ; i< argc ; i++) {
        string arg = args[i];

        if (arg[0] == '-') 
        {
            if (arg == "-cc") {
                bCheckCc = true;
            } else if (arg == "-ccall") {
                bCheckCcAll = true;
            } else if (arg == "-tc") {
                bCheckTc = true;
            } else if (arg == "-ronly") {
                bRonly = true;
                i++;
                if ( i>= argc) {
                    helpMsg();
                    return 1;
                }
                ronlyFile = args[i];
            } else if (arg == "-conly") {
                bConly = true;
                i++;
                if ( i>= argc) {
                    helpMsg();
                    return 1;
                }
                conlyFile = args[i];
            } else if (arg == "-norc") {
                bNorc = true;
                i++;
                if ( i>= argc) {
                    helpMsg();
                    return 1;
                }
                norcFile = args[i];
            } else if (arg == "-svs") {
                bSvs = true;
                i++;
                if ( i>= argc) {
                    helpMsg();
                    return 1;
                }
                svsFile = args[i];
            } else if (arg == "-sync") {
                bSync = true;
                i++;
                if ( i>= argc) {
                    helpMsg();
                    return 1;
                }
                syncFile = args[i];
            } else if (arg == "-debug") {
                bDebug = true;
            } else if (arg == "-dot") {
                bDot = true;
                i++;
                if ( i>= argc) {
                    helpMsg();
                    return 1;
                }
                dotNet = args[i];
            } else if (arg == "-p2p") {
                bP2p = true;
                i++;
                if ( i>= argc) {
                    helpMsg();
                    return 1;
                }
                p2pNet = args[i];

            } else {
                helpMsg();
                return 1;
            }
        } 
        else {
            inFile = arg;
        }
    }


    if (!bCheckTc && !bCheckTcAll && !bCheckCcAll && !bCheckCc && !bRonly &&
        !bConly && !bSvs && !bSync && !bDebug && !bNorc  && !bDot && !bP2p ) 
    {
        bCheckTc = true; 
    }
    
    SpiceParser* parser = NULL;
    parser = new SpiceParser( inFile );
    parser->parse();

    

    //-- checking!
    //
    vector<Subckt*> tops = parser->getDesign().getTops();
    if (tops.size() > 1) {
        throw SpiceParserException("ERROR: More than 1 top cell");
    }

    if (bDebug) {
        cout << parser->getDesign().getTop0()->to_string_debug();
    }

    //-- collecting
    //
    if (bCheckTc) 
    {
        Subckt* p = tops[0];
        for (unsigned i=0; i<p->_ports.size(); i++) 
        {
            //--- 1. use net to get group id
            //
            SubcktNet* pnet = p->_ports[i];
            SubcktNetGroupID nid = pnet->_id;
           
            //--- 2. use group id to get all connected nets
            //
            double totalC = 0;
            vector<SubcktNet*>::iterator nit = p->_idNetMap[nid].begin(); 
            for (; nit != p->_idNetMap[nid].end(); nit++) 
            {
                SubcktNet* pn = *nit;
                // 
                //--- 3. find caps connected to each of the nets
                //
                vector<SubcktInst*>::iterator iit = pn->_insts.begin();
                for (; iit != pn->_insts.end(); iit++) {
                    SubcktInst* pi = *iit;
                    if (pi->_cell->_type == Subckt::CAP) {
                        totalC += pi->_value;
                    }
                }
            }
            cout << pnet->_name << " " << totalC << endl;
        }
    }


    if (bCheckCc) 
    {
        Subckt* p = tops[0];
        for (unsigned i=0; i<p->_ports.size(); i++) 
        {
            SubcktNet* pnet1 = p->_ports[i];
            SubcktNet* pnet2 = NULL;
            SubcktNetGroupID nid1 = pnet1->_id;

            for (unsigned j=i+1; j<p->_ports.size(); j++) 
            {
                pnet2 = p->_ports[j];
                SubcktNetGroupID nid2 = pnet2->_id;
                double cc = 0;
                map<string,SubcktInst*>::iterator iit = p->_instMap.begin();

                while (iit != p->_instMap.end()) {
                    SubcktInst* pinst = iit->second;
                    if (pinst->_cell->_type == Subckt::CAP) {
                        double tid1 = pinst->_pins[0]->_id;
                        double tid2 = pinst->_pins[1]->_id;
                        if (( tid1 == nid1 && tid2 == nid2 ) || 
                            ( tid2 == nid1 && tid1 == nid2 ) )
                        {
                            cc += pinst->_value;
                        }
                    }
                    ++iit;
                }
                cout << pnet1->_name << " " << pnet2->_name << " " << cc << endl;
            }
        }
    }


    if (bCheckCcAll) 
    {
        Subckt* p = tops[0];
        map<NetPair, double, NetPairCompare> ccMap;

        //--- 1. Put each cap instace to different bucket based on the two nets it connects
        //       The bucket is labeled by pin pair "NetPair". 
        //
        map<string,SubcktInst*>::iterator iit = p->_instMap.begin();
        for (; iit != p->_instMap.end(); ++iit)
        {
            SubcktInst* pinst = iit->second;
            if (pinst->_cell->_type == Subckt::CAP) 
            {
                SubcktNetGroupID n1 = pinst->_pins[0]->_id;
                SubcktNetGroupID n2 = pinst->_pins[1]->_id;

                map<NetPair, double, NetPairCompare>::iterator pit = ccMap.find( NetPair(n1, n2) );
                if ( pit == ccMap.end() ) {
                    ccMap[ NetPair(n1,n2) ] = pinst->_value;
                }  
                else {
                    ccMap[ NetPair(n1,n2) ] += pinst->_value;
                }
            }
        }

        //--- 2. Get result from each bucket
        //
        for ( map<NetPair, double, NetPairCompare>::iterator pit = ccMap.begin(); pit != ccMap.end(); ++pit)
        {
            //--TODO, see if there's better huristic to name the net
            //
            SubcktNet* n1 = p->_idNetMap[ pit->first.a ][0];
            SubcktNet* n2 = p->_idNetMap[ pit->first.b ][0];
            double value = pit->second; 
            cout << n1->_name << " " << n2->_name << " " << value << endl;
        }
    }

    if (ronlyFile != "") {
        Subckt* p = tops[0];
        ofstream ronlyfs( ronlyFile.c_str() ); 
        ronlyfs << p->to_string_ronly();
        ronlyfs.close();
    }

    if (conlyFile != "") {
        Subckt* p = tops[0];
        ofstream conlyfs( conlyFile.c_str() ); 
        conlyfs << p->to_string_conly();
        conlyfs.close();
    }

    if (norcFile != "") {
        Subckt* p = tops[0];
        ofstream norcfs( norcFile.c_str() ); 
        norcfs << p->to_string_norc();
        norcfs.close();
    }


    if (svsFile != "") 
    {
        // generate source file with LVS compatiable rules
        // 1. create user defined Subckt
        // 2. Rename 
        //
        SpiceParser* parser2 = new SpiceParser( svsFile );
        parser2->parse();

        vector<Subckt*> tops2 = parser2->getDesign().getTops();
        if (tops2.size() > 1) {
            throw SpiceParserException("ERROR: More than 1 top cell");
        }
        else if ( tops[0]->_name != tops2[0]->_name ) {
            cout << "ERROR: Two netlists have different top cell names" << endl;
            cout << "  " <<  tops[0]->_name << " and " << tops2[0]->_name << endl;
            return 1;
        }

        //--- write the file with "lvs_comaptible" setting.
        ofstream ssrc("src.spf");
        ssrc << parser->getDesign().to_string();
        ssrc.close();

        ofstream star("tar.spf");
        star << parser2->getDesign().to_string();
        star.close();

        // write the lvs deck:
        ofstream svs("svs.lvs");
        svs << to_string_svs ( tops[0]->_name , tops2[0]->_name);
        svs.close();
        int ret = system("calibre -lvs svs.lvs |tee lvs.log");
        cout << "LVS result " << ret << endl;
        delete parser2;
    }


    if (syncFile != "") 
    {
        SpiceParser* parser2 = new SpiceParser( syncFile );
        parser2->parse();

        vector<Subckt*> tops2 = parser2->getDesign().getTops();
        if ( tops[0]->_name != tops2[0]->_name ) {
            cout << "ERROR: Two netlists have different top cell names" << endl;
            cout << "  " <<  tops[0]->_name << " and " << tops2[0]->_name << endl;
            return 1;
        }

        ofstream ssrc("src.spf");
        ssrc << parser->getDesign().to_string();
        ssrc.close();

        ofstream star("tar.spf");
        star << parser2->getDesign().to_string();
        star.close();


        // write the lvs deck:
        ofstream svs("svs.lvs");
        svs << to_string_svs ( tops[0]->_name , tops2[0]->_name);
        svs.close();
        int ret = system("$MGC_HOME/bin/calibre -lvs svs.lvs > lvs.log");

        if (ret == 0) {
            //
            // read in ixf file, which is in "tar_num tar_name src_num src_name" format
            //
            map<string,string> instNameMap;
            stringstream ss2;
            unsigned int snum, tnum;
            string       sname, tname;

            ss2 << "svdb/" << parser->getDesign().getTop0()->_name << ".ixf";
            ifstream ixf( ss2.str().c_str() ); 
            
            while ( ixf >> tnum >> tname >> snum >> sname ) {
                instNameMap[ tname ] = sname;
            }

            // rename the instance name, and reassign netid for the target netlist.
            Subckt* p1 = parser->getDesign().getTop0();
            Subckt* p2 = parser2->getDesign().getTop0();

            // rename instance
            //
            map<string,string>::iterator iit = instNameMap.begin();
            map<string,SubcktInst*> newInstMap;
            map<SubcktNet*,SubcktNet*>  renamedPinMap; // ksy=targetNet, value=sourceNet

            for (; iit != instNameMap.end(); ++iit) {
                string tname = iit->first;
                string sname = iit->second;
                SubcktInst* pinst_src = p1->_instMap[sname];
                SubcktInst* pinst = p2->_instMap[tname];
                 
                // rename instance
                //
                pinst->_name = pinst_src->_name;

                // rename non-premitive instance pin names as well
                //
                if (pinst_src->_cell->_type == Subckt::USER) 
                {
                    for (unsigned k=0; k<pinst_src->_pins.size(); ++k) 
                    {
                        //-- rename only non-port nets
                        //
                        if (pinst_src->_pins[k]->_cPort == 0)
                        {
                            map<string,SubcktNet*>::iterator nit = p2->_netMap.find( pinst_src->_pins[k]->_name );

                            if (nit != p2->_netMap.end()) {
                                // TODO: should try to makeup a new name that has no confliction
                                //
                                stringstream ss;
                                ss << "ERROR: Sync net name from source netlist, ";
                                ss << pinst_src->_pins[k]->_name << " already exists in target netlist";
                                throw SpiceParserException ( ss.str().c_str() );
                            }

                            map<SubcktNet*,SubcktNet*>::iterator xit = renamedPinMap.find( pinst->_pins[k] ); 

                            if (xit == renamedPinMap.end()) {
                                // -- not renamed yet
                                //
                                pinst->_pins[k]->_name = pinst_src->_pins[k]->_name;
                                renamedPinMap[ pinst->_pins[k] ]  = pinst_src->_pins[k]; 
                            } 
                            else {
                                // already renamed. Rename again only if the new name has higher priority 
                                //
                                if ( compare_subckNet_pointer(pinst_src->_pins[k], pinst->_pins[k]) )  
                                {
                                    pinst->_pins[k]->_name = pinst_src->_pins[k]->_name;
                                    renamedPinMap[ pinst->_pins[k] ]  = pinst_src->_pins[k]; 
                                }
                            }
                        }
                    }
                }
                newInstMap[sname] = pinst;
            }
            p2->_instMap = newInstMap;
             
            // re-create _netMap since some of the net names are updated in previous stage
            //
            map<string,SubcktNet*> newNetMap;
            map<string,SubcktNet*>::iterator mit = p2->_netMap.begin();
            for (; mit != p2->_netMap.end(); ++mit)
            {
                SubcktNet* np = mit->second;
                newNetMap[ np->_name ] = np; 
            }
            p2->_netMap = newNetMap;

            // sort _idNetMap again since some of the net names are updated in previous stage
            //
            map< SubcktNetGroupID, vector<SubcktNet*> >::iterator nit = p2->_idNetMap.begin();
            for (; nit != p2->_idNetMap.end(); ++nit) 
            {
                // sort vector SubcktNet* pointer in _idNetMap
                std::sort( nit->second.begin(), nit->second.end(), compare_subckNet_pointer);
            }
            
            cout << p2->to_string();
        }
        else {
            cout << "LVS result " << ret << endl;
            cout << "ERROR: SVS fail while generating ixf and nxf file";
            return 1;
        }

        delete parser2;
    }


    if (dotNet != "") {
        Subckt* p = tops[0];
        DotGen dotGen( p );

        if ( iequal(dotNet ,"ports")) {
            for (unsigned x=0; x<p->_ports.size(); x++) {
                dotGen.gen( p->_ports[x]->_name  );
            } 
        } else {

            map<string,SubcktNet*>::iterator mit = p->_netMap.find( dotNet );

            if (mit != p->_netMap.end()) {
                dotGen.gen( dotNet );
            } else {
                cout << "ERROR: invalid net name " << dotNet << endl;
            }
        }
    }

    if (p2pNet != "") {
        Subckt* p = tops[0];
        P2pGen p2pGen( p );

        if ( iequal(p2pNet ,"ports")) {
            for (unsigned x=0; x<p->_ports.size(); x++) {
                p2pGen.run_calcd( p->_ports[x]->_name  );
            } 
        } else {

            map<string,SubcktNet*>::iterator mit = p->_netMap.find( p2pNet );

            if (mit != p->_netMap.end()) {
                p2pGen.run_calcd( p2pNet );
            } else {
                cout << "ERROR: invalid net name " << p2pNet << endl;
            }
        }
    }

    delete parser;
    return 0;
}







