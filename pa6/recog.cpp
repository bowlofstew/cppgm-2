// (C) 2013 CPPGM Foundation www.cppgm.org.  All rights reserved.

#ifndef PA6
#pragma once
#endif

#include <stdarg.h>
#include <vector>
#include <string>
#include <stdexcept>
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


    void parse() {
    }

    void parse__primary_expression() {
        if (_ptIt->type == PT_KW_TRUE || 
            _ptIt->type == PT_KW_FALSE ||
            _ptIt->type == PT_KW_NULLPTR || 
            is_TT_LITERAL(_ptIt->type) ||
            _ptIt->type == PT_KW_THIS)
        {
            matchAny();
            return;
        }
        else if (_ptIt->type == PT_OP_LPAREN) 
        {
            match(PT_OP_LPAREN);
            //parse__expression();
            match(PT_OP_RPAREN);
        }
        else if (_ptIt->type) {
        }
        
    }

    void match( int num, EPostTokenType t1, ... ) 
    {
        EPostTokenType t = _ptIt->type; 
        va_list args;
        va_start (args, t1);
        for (int i=0; i<num; i++) {
            EPostTokenType tt = va_arg(args, EPostTokenType);
            if (tt==t) {
                va_end(args);
                _ptIt++;
                return;
            }
        }
        va_end(args);
        throw RecognizerException("Recog: matching error!");
        return;
    }

    void match( EPostTokenType tp )
    {
        if (_ptIt == _ptEnd) {
            throw RecognizerException("Recog: matching error! Met EOF.");
        }
        else if (_ptIt->type == tp) {
            _ptIt++;
            return;
        }
        else {
            throw RecognizerException("Recog: matching error!");
            return;
        }
    }

    void matchAny() 
    {
        if (_ptIt == _ptEnd) {
            throw RecognizerException("Recog: matching error! Met EOF.");
        }
        _ptIt++;
    }
    
  private:
    vector<PostToken> _ptVec;
    PtIt              _ptIt;
    PtIt              _ptEnd;

};



void DoRecog(const string& srcfile)
{
    vector<PostToken> ptVec;
    preproc(srcfile, ptVec);

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
