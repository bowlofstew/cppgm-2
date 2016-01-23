#ifndef __SUBCKT_H_
#define __SUBCKT_H_


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <exception>
#include <map>
#include <limits>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include "pproc.h"

#define EQUAL(x,y) fabs((x)-(y)) < 1E-8

class SpiceParserException : public std::exception
{
  public:
    SpiceParserException (const char* msg)
      : _errMsg(msg)
    {
    }

    virtual ~SpiceParserException() throw()
    {
    }

    virtual const char* what() const throw()
    {
        return _errMsg.c_str();
    }

  private:
    std::string _errMsg;

};


class SubcktInst;
class SubcktNet;
class Subckt;
class SpiceDesign;
typedef long SubcktNetGroupID;



class SubcktNet {
  public:
    SubcktNet ( const std::string& name ); 
    ~SubcktNet();
    void connect( SubcktInst* inst );
    const std::string& to_string();

    std::string              _name;
    std::vector<SubcktInst*> _insts;
    SubcktNetGroupID         _id;
    unsigned                 _cPin;
    unsigned                 _cPort;
};


class SubcktInst {
  public:
    SubcktInst ( Subckt* pparent, Subckt* pcell, const std::string& name );
    SubcktNet* connect ( SubcktNet* n1);
    SubcktNet* connect ( SubcktNet* n1, SubcktNet* n2);
    std::string to_string();

    Subckt*      _parent;
    Subckt*      _cell;
    std::string  _name;
    std::string  _prop; 
    double       _value;
    std::vector<SubcktNet*>     _pins;  // by port declaration order
};


class Subckt {
  public:
    enum Type {
        RES,
        CAP,
        USER
    };

    Subckt ( const std::string& name ) ;
    ~Subckt();
    SubcktNet* create_port ( const std::string& portName );
    SubcktInst* make_inst ( Subckt* cell, const std::string& name, const std::vector<std::string>& pins );
    SubcktInst* make_dual_port_inst (Subckt* cell, const std::string& name, const std::string& n1, const std::string& n2); 
    SubcktNet* make_net (const std::string& name, SubcktNetGroupID id=0);
    void make_id ( SubcktNet* pnet );
    void assign_id ( SubcktNet* src, SubcktNet* tar );
    void merge_id ( SubcktNet* net1, SubcktNet* net2);
    std::string to_string();
    std::string to_string_conly( );
    std::string to_string_ronly( );
    std::string to_string_norc( );
    std::string to_string_debug ();

    Type                                 _type;
    std::string                          _name;
    std::map<std::string,SubcktInst*>    _instMap;
    std::vector<SubcktInst*>             _insts;
    std::map<std::string,SubcktNet*>     _portMap;
    std::vector<SubcktNet*>              _ports;
    std::map<std::string,SubcktNet*>     _netMap;
    std::map<std::string,Subckt*>        _childCellMap;

    unsigned long                    _idCount;
    std::vector<SubcktNetGroupID>    _idList;
    std::map< SubcktNetGroupID, std::vector<SubcktNet*> >  _idNetMap;
    unsigned long  _referenceCount;
};


class SpiceDesign {
  public:
    SpiceDesign ();
    ~SpiceDesign (); 
    Subckt* make_subckt( const std::string &name ); 
    void addTop( Subckt* top );
    std::vector<Subckt*> getTops() ;
    Subckt* getTop0() ;

    std::map<std::string,Subckt*> _subcktMap;
    std::vector<Subckt*>          _subckts;
    std::vector<Subckt*>          _tops;
    std::string to_string();
    std::string to_string_norc();
};


#endif









