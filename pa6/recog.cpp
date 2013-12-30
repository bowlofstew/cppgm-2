// (C) 2013 CPPGM Foundation www.cppgm.org.  All rights reserved.

#ifndef PA6
#pragma once
#endif

#include <stdarg.h>
#include <map>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <memory>
#include <fstream>
#include <iostream>
#include <exception>
#include "preproc.cpp"

using namespace std;

bool PA6_IsClassName(const string& identifier)
{
	return identifier.find('C') != string::npos;
}

bool PA6_IsTemplateName(const string& identifier)
{
	return identifier.find('T') != string::npos;
}

bool PA6_IsTypedefName(const string& identifier)
{
	return identifier.find('Y') != string::npos;
}

bool PA6_IsEnumName(const string& identifier)
{
	return identifier.find('E') != string::npos;
}

bool PA6_IsNamespaceName(const string& identifier)
{
	return identifier.find('N') != string::npos;
}


class RecognizerException : public exception {
  public:
    RecognizerException(const char* msg) 
        : _msg(msg)
    {
    }

    virtual ~RecognizerException() throw () {
    }

    virtual const char* what() const throw() {
        return _msg.c_str();
    }

  private:
    string _msg;
};


enum AstType {
    AST_ERROR,
    AST_EMPTY,
    AST_TOKEN,
    AST_COMPOUND    
};


class CppAst {
  public:
    CppAst() {
    }
    virtual ~CppAst() {
    }

    virtual string name() {
        return "";
    }

    virtual AstType type() = 0;  
    virtual void dump() {}
    virtual int size() = 0;
    virtual bool error() = 0;
};

typedef shared_ptr<CppAst> CppAstPtr;

class ErrorAst : public CppAst {
  public:
    ErrorAst() {}
    ~ErrorAst() {
    }
    void dump() {} 

    AstType type() {
        return AST_ERROR;
    }

    int size() { 
        return -1;
    }

    bool error() {
        return true;
    }

};


class EmptyAst : public CppAst {
  public:
    EmptyAst() {}
    ~EmptyAst() {
    }
    void dump() {} 

    AstType type() {
        return AST_EMPTY;
    }

    int size() {
        return 0;
    }

    bool error() {
        return false;
    }
};


class TokenAst : public CppAst {
  public:
    TokenAst() {}
    ~TokenAst() {
    }
    void dump() {} 
    AstType type()
    {
        return AST_TOKEN;
    }

    int size() {
        return 1;
    }

    bool error() {
        return false;
    }

    PostToken pt;
};


class CompAst : public CppAst {
  public:
    CompAst() {}
    ~CompAst() {
    }
    void dump() {} 
    AstType type()
    {
        return AST_COMPOUND;
    }

    int size() {
        map<string, CppAstPtr>::iterator mit = astMap.begin();
        int count = 0;
        for ( ; mit != astMap.end(); ++mit )
        {
            count += mit->second->size(); 
        }
        return count;
    }

    bool error() {
        map<string, CppAstPtr>::iterator mit = astMap.begin();
        bool flag = false;
        for ( ; mit != astMap.end(); ++mit )
        {
            flag |= mit->second->error(); 
        }
        return flag;
    }

    map<string, CppAstPtr> astMap; 
};


class Autocat {
  public: 
    static int depth;

    Autocat(string s) 
        : name (s)
    {
        depth++;
        cout << indent() << "entering... " << name << endl;
    }
    ~Autocat() 
    {
        cout << indent() << "leaving... " << name << endl;
        depth--;
    }

    string indent() 
    {
        stringstream ss;
        for (int i=0; i<depth*2; i++) {
            ss << " ";
        }
        return ss.str();
    }

    string name;
};


int Autocat::depth = 0;


class Recognizer {
  public: 
    typedef vector<PostToken>::iterator PtIt;

    Recognizer( vector<PostToken>& ptVec ) 
        : _ptVec(ptVec)
    {
        _ptIt = _ptVec.begin();
        _ptEnd = _ptVec.end();
    }     

    ~Recognizer() {
    }

    inline bool is_TT_LITERAL(EPostTokenType type) {
        if (type == PT_LITERAL || type == PT_LITERAL_ARRAY || type == PT_UD_LITERAL || type == PT_UD_LITERAL_ARRAY) {
            return true;
        }
        return false;
    }

    std::string to_string(const unsigned int i)
    {
        return std::to_string( (long long unsigned) i);
    }

#include "code.cpp"


    bool parse() {
        parse__translation_unit();

        if (_ptIt == _ptEnd) {
            return true;
        } 
        else {
            return false;
        }
    }


    bool matchType( EPostTokenType tp , EPostTokenType tp2) 
    {
        bool bOK = false ;

        if (tp == tp2) 
        {
            bOK = true;
        }
        else if (tp == PT_TT_IDENTIFIER && tp2 == PT_SIMPLE ) 
        {
            bOK = true;
        }
        else if (tp == PT_TT_IDENTIFIER_C && tp2 == PT_SIMPLE ) 
        {
            if ( PA6_IsClassName( _ptIt->source )) {
                bOK = true;
            } 
        }
        else if (tp == PT_TT_IDENTIFIER_E && tp2 == PT_SIMPLE ) 
        {
            if (PA6_IsTemplateName ( _ptIt->source )) {
                bOK = true;
            }
        }
        else if (tp == PT_TT_IDENTIFIER_N && tp2 == PT_SIMPLE ) 
        {
            if (PA6_IsNamespaceName ( _ptIt->source ) ) {
                bOK = true;
            }
        }
        else if (tp == PT_TT_IDENTIFIER_T && tp2 == PT_SIMPLE ) 
        {
            if (PA6_IsTemplateName (_ptIt->source) ) {
                bOK = true;
            }
        }
        else if (tp == PT_TT_IDENTIFIER_Y && tp2 == PT_SIMPLE ) 
        {
            if (PA6_IsTypedefName( _ptIt->source )) {
                bOK = true;
            }
        }
        else if ( tp == PT_TT_LITERAL ) 
        {
            if (tp2 == PT_LITERAL || tp2 == PT_LITERAL_ARRAY || tp2 == PT_UD_LITERAL || tp2 == PT_UD_LITERAL_ARRAY)
            {
                bOK = true;
            }
        }
        else if ( tp == PT_ST_EMPTYSTR) 
        {
            if (_ptIt->type == PT_LITERAL_ARRAY && _ptIt->ltype == FT_CHAR && _ptIt->size == 1)
            {
                bOK = true;
            }
        }
        else if ( tp == PT_ST_ZERO ) 
        {
            if (_ptIt->type == PT_LITERAL && _ptIt->source == "0") {
                bOK = true; 
            } 
        }
        else if ( tp == PT_ST_OVERRIDE && _ptIt->type == PT_SIMPLE && _ptIt->source == "override" )
        {
            bOK = true;
        }
        else if ( tp == PT_ST_FINAL && _ptIt->type == PT_SIMPLE && _ptIt->source == "final" )
        {
            bOK = true;
        }
        else if ( tp == PT_ST_NONPAREN) 
        {
            if ( tp2 == PT_OP_LPAREN || tp2 == PT_OP_RPAREN || 
                 tp2 == PT_OP_LSQUARE || tp2 == PT_OP_RSQUARE || 
                 tp2 == PT_OP_LBRACE || tp2 == PT_OP_RBRACE ||
                 tp2 == PT_ST_EOF) {
                bOK = true;
            }
        }
        else if (tp == PT_ST_EOF && tp2 == PT_EOF )
        {
            bOK = true;
        }

        return bOK;
    }

    
    shared_ptr<CppAst> match( EPostTokenType tp )
    {
        if (_ptIt == _ptEnd) {
            return shared_ptr<CppAst>( new ErrorAst() );
        }


        bool bOK = false ;

        EPostTokenType tp2 = _ptIt->type;

        bOK = matchType( tp , tp2);

        // if (tp == tp2) 
        // {
        //     bOK = true;
        // }
        // else if (tp == PT_TT_IDENTIFIER && tp2 == PT_SIMPLE ) 
        // {
        //     bOK = true;
        // }
        // else if (tp == PT_TT_IDENTIFIER_C && tp2 == PT_SIMPLE ) 
        // {
        //     if ( PA6_IsClassName( _ptIt->source )) {
        //         bOK = true;
        //     } 
        // }
        // else if (tp == PT_TT_IDENTIFIER_E && tp2 == PT_SIMPLE ) 
        // {
        //     if (PA6_IsTemplateName ( _ptIt->source )) {
        //         bOK = true;
        //     }
        // }
        // else if (tp == PT_TT_IDENTIFIER_N && tp2 == PT_SIMPLE ) 
        // {
        //     if (PA6_IsNamespaceName ( _ptIt->source ) ) {
        //         bOK = true;
        //     }
        // }
        // else if (tp == PT_TT_IDENTIFIER_T && tp2 == PT_SIMPLE ) 
        // {
        //     if (PA6_IsTemplateName (_ptIt->source) ) {
        //         bOK = true;
        //     }
        // }
        // else if (tp == PT_TT_IDENTIFIER_Y && tp2 == PT_SIMPLE ) 
        // {
        //     if (PA6_IsTypedefName( _ptIt->source )) {
        //         bOK = true;
        //     }
        // }
        // else if ( tp == PT_TT_LITERAL ) 
        // {
        //     if (tp2 == PT_LITERAL || tp2 == PT_LITERAL_ARRAY || tp2 == PT_UD_LITERAL || tp2 == PT_UD_LITERAL_ARRAY)
        //     {
        //         bOK = true;
        //     }
        // }
        // else if ( tp == PT_ST_EMPTYSTR) 
        // {
        //     if (_ptIt->type == PT_LITERAL_ARRAY && _ptIt->ltype == FT_CHAR && _ptIt->size == 1)
        //     {
        //         bOK = true;
        //     }
        // }
        // else if ( tp == PT_ST_ZERO ) 
        // {
        //     if (_ptIt->type == PT_LITERAL && _ptIt->source == "0") {
        //         bOK = true; 
        //     } 
        // }
        // else if ( tp == PT_ST_OVERRIDE && _ptIt->type == PT_SIMPLE && _ptIt->source == "override" )
        // {
        //     bOK = true;
        // }
        // else if ( tp == PT_ST_FINAL && _ptIt->type == PT_SIMPLE && _ptIt->source == "final" )
        // {
        //     bOK = true;
        // }
        // else if ( tp == PT_ST_NONPAREN) 
        // {
        //     if ( tp2 == PT_OP_LPAREN || tp2 == PT_OP_RPAREN || 
        //          tp2 == PT_OP_LSQUARE || tp2 == PT_OP_RSQUARE || 
        //          tp2 == PT_OP_LBRACE || tp2 == PT_OP_RBRACE ||
        //          tp2 == PT_ST_EOF) {
        //         bOK = true;
        //     }
        // }
        // else if (tp == PT_ST_EOF && tp2 == PT_EOF )
        // {
        //     bOK = true;
        // }

        if (bOK)
        {
            cout << "MATCHED: " << PostTokenTypeToStringMap.at( tp ) << " to " <<  _ptIt->source << endl;
            TokenAst* ast = new TokenAst();
            ast->pt = *_ptIt;
            _ptIt++;
            return shared_ptr<CppAst>( ast );
        }
        else {
            return shared_ptr<CppAst>( new EmptyAst );
        }

    }

    // bool match( int num, EPostTokenType t1, ... ) 
    // {
    //     EPostTokenType t = _ptIt->type; 
    //     va_list args;
    //     va_start (args, t1);
    //     for (int i=0; i<num; i++) {
    //         EPostTokenType tt = va_arg(args, EPostTokenType);
    //         if (tt==t) {
    //             va_end(args);
    //             _ptIt++;
    //             return true;
    //         }
    //     }
    //     va_end(args);
    //     return false;
    // }

    // bool match( EPostTokenType tp )
    // {
    //     if (_ptIt == _ptEnd) {
    //         return false;
    //     }
    //     else if (_ptIt->type == tp) {
    //         _ptIt++;
    //         return true;
    //     }
    //     else {
    //         return false;
    //     }
    // }

    // bool matchAny() 
    // {
    //     if (_ptIt == _ptEnd) {
    //         return false;
    //     }
    //     _ptIt++;
    //     return true;
    // }

    // to keep the current position for backtracking
    //
    void pushPosition() 
    {
        _bakIts.push( _ptIt );
    }

    void popPosition()
    {
        _ptIt = _bakIts.top(); 
        _bakIts.pop();
    }

    string lastErrFile() {
        return _errFile.back();
    }

    int lastErrLine() {
        return _errLine.back();
    }

    
  private:
    vector<PostToken> _ptVec;
    PtIt              _ptIt;
    PtIt              _ptEnd;
    stack<PtIt>       _bakIts;

    vector<string>    _errFile;
    vector<int>       _errLine;

    CppAst*           _lastAst;
    CppAst*           _curAst;

};



void DoRecog(const string& srcfile)
{
    vector<PostToken> ptVec;
    preproc(srcfile, ptVec);

    //----- replace the shift1 and shift2 tokens
    //
    vector<PostToken> tokens;
    for (unsigned i=0 ; i<ptVec.size() ; i++) {
        if (ptVec[i].type == PT_OP_RSHIFT) {
            PostToken t1, t2;
            t1.type = PT_ST_RSHIFT_1;
            t2.type = PT_ST_RSHIFT_2;
            tokens.push_back(t1); 
            tokens.push_back(t2); 
        } 
        else {
            tokens.push_back(ptVec[i]);
        }
    }

    Recognizer recognizer( tokens );

    if (recognizer.parse() == false) {
        stringstream ss;
        // ss << "Parsing error at " << recognizer.lastErrFile() << ", line" << recognizer.lastErrLine(); 
        ss << "Parsing error!"; 
        throw RecognizerException(ss.str().c_str());
    }

};


#ifdef PA6
int main(int argc, char** argv)
{
	try
	{
		vector<string> args;

		for (int i = 1; i < argc; i++)
			args.emplace_back(argv[i]);

		if (args.size() < 3 || args[0] != "-o")
			throw logic_error("invalid usage");

		string outfile = args[1];
		size_t nsrcfiles = args.size() - 2;

		ofstream out(outfile);

		out << "recog " << nsrcfiles << endl;

		for (size_t i = 0; i < nsrcfiles; i++)
		{
			string srcfile = args[i+2];

			try
			{
				DoRecog(srcfile);
				out << srcfile << " OK" << endl;
			}
			catch (exception& e)
			{
				cerr << e.what() << endl;
				out << srcfile << " BAD" << endl;
			}
		}
	}
	catch (exception& e)
	{
		cerr << "ERROR: " << e.what() << endl;
		return EXIT_FAILURE;
	}
}
#endif
