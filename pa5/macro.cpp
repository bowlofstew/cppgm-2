// (C) 2013 CPPGM Foundation www.cppgm.org.  All rights reserved.

#ifndef PA4
#pragma once
#endif

#include <list>
#include <string>
#include "utf8.cpp"
#include "utf16.cpp"
#include "pptoken.cpp"
#include "posttoken.cpp"
#include "ctrlexpr.cpp"

using namespace std;


// For pragma once implementation:
// system-wide unique file id type `PA5FileId`
typedef pair<unsigned long int, unsigned long int> PA5FileId;

// bootstrap system call interface, used by PA5GetFileId
extern "C" long int syscall(long int n, ...) throw ();

// PA5GetFileId returns true iff file found at path `path`.
// out parameter `out_fileid` is set to file id
bool PA5GetFileId(const string& path, PA5FileId& out_fileid)
{
	struct
	{
			unsigned long int dev;
			unsigned long int ino;
			long int unused[16];
	} data;

	int res = syscall(4, path.c_str(), &data);

	out_fileid = make_pair(data.dev, data.ino);

	return res == 0;
}


// OPTIONAL: Also search `PA5StdIncPaths` on `--stdinc` command-line switch (not by default)
vector<string> PA5StdIncPaths =
{
    "/usr/include/c++/4.7/",
    "/usr/include/c++/4.7/x86_64-linux-gnu/",
    "/usr/include/c++/4.7/backward/",
    "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/",
    "/usr/local/include/",
    "/usr/lib/gcc/x86_64-linux-gnu/4.7/include-fixed/",
    "/usr/include/x86_64-linux-gnu/",
    "/usr/include/"
};


class DirectiveHandlerException : public exception
{
  public:
    DirectiveHandlerException(const char* msg)
       : _errMsg(msg)
    {
    }

    virtual ~DirectiveHandlerException() throw() 
    {
    }

    virtual const char* what() const throw() 
    { 
        return _errMsg.c_str(); 
    }

  private:
    string _errMsg;
};


enum MacroPPTokenType
{
    DEFINE=1,
    UNDEF,
    IF,
    IFDEF,
    IFNDEF,
    ELIF,
    ELSE,
    ENDIF,
    INCLUDE,
    LINE,
    ERROR,
    PRAGMA,
    TXT,
    INVALID
};


struct MacroPPToken
{
    MacroPPTokenType type;
    list<PPToken>    pplst;
};


struct Directive {

    enum {
        OBJ = 1,
        FUN
    };

    string          name;
    int             type;     //0: object , 1:func
    int             paraNum;

    map<string,int> paramMap;
    vector<string>  paramLst;
    vector<PPToken> replaceLst;
};


const map<string, MacroPPTokenType> string2macroPPTokenTypeMap = 
{
    { "define", DEFINE },
    { "undef", UNDEF},
    { "if",  IF},
    { "ifdef",  IFDEF},
    { "ifndef",  IFNDEF},
    { "elif",   ELIF},
    { "else",   ELSE},
    { "endif",  ENDIF },
    { "include",  INCLUDE},
    { "line",  LINE},
    { "error",  ERROR},
    { "pragma",  PRAGMA},
    { "TXT",  TXT}
};


class DirectiveHandler {

  public:
    DirectiveHandler (string srcfile, vector<PPToken>& pps)
        : _srcfile(srcfile), _pps(pps)
    {
        initialize_default_directive();
        _pragmaOnce = false;
    }

    ~DirectiveHandler () {}


    PPToken makePPToken(string s, int lineNo=-1)
    {
        int code_unit;
        vector<int> uncTokens;
        UTF8Decoder utf8Decoder(&s);
        while ((code_unit = utf8Decoder.nextCode()) > 0)
        {
            uncTokens.push_back(code_unit);
        }

        PPTokenizer tokenizer;
        tokenizer.parse( uncTokens );
        tokenizer._elst.pop_back();  // remove eof

        if (tokenizer._elst.size() != 1)
        {
            throw DirectiveHandlerException("Fail making a token out of a string");
        }

        tokenizer._elst[0].lineNo = lineNo;

        return tokenizer._elst[0];  
    }

    PPToken makePPToken(int s, int lineNo=-1)
    {
        return makePPToken(to_string(s), lineNo);
    }


    bool isConcatOp( string s )
    {
        if (s == "##" || s == "%:%:")
            return true;
        else
            return false;
    }

    bool isDirectiveStartOp( string s )
    {
        if (s == "#" || s == "%:")
            return true;
        else
            return false;
    }



//    enum {
//        OBJ = 1,
//        FUN
//    };
//
//    string          name;
//    int             type;     //0: object , 1:func
//    int             paraNum;
//
//    map<string,int> paramMap;
//    vector<string>  paramLst;
//    vector<PPToken> replaceLst;

    void initialize_default_directive()
    {
        string s;
        Directive* dir;

        s = "__CPPGM__";
        dir = new Directive;
        dir->name = "__CPPGM__"; 
        dir->type = Directive::OBJ;
        dir->paraNum = 0;
        dir->replaceLst.push_back( makePPToken("201303L") );
        _directiveLst[s] = dir;

        s = "__cplusplus";
        dir = new Directive;
        dir->name = "__cplusplus"; 
        dir->type = Directive::OBJ;
        dir->paraNum = 0;
        dir->replaceLst.push_back( makePPToken("201103L") );
        _directiveLst[s] = dir;

        s = "__STDC_HOSTED__";
        dir = new Directive;
        dir->name = "__STDC_HOSTED__"; 
        dir->type = Directive::OBJ;
        dir->paraNum = 0;
        dir->replaceLst.push_back( makePPToken("1") );
        _directiveLst[s] = dir;

        s = "__CPPGM_AUTHOR__";
        dir = new Directive;
        dir->name = "__CPPGM_AUTHOR__"; 
        dir->type = Directive::OBJ;
        dir->paraNum = 0;
        dir->replaceLst.push_back( makePPToken("\"Rich Huang\"") );
        _directiveLst[s] = dir;

        s = "__FILE__";
        dir = new Directive;
        dir->name = "__FILE__"; 
        dir->type = Directive::OBJ;
        dir->paraNum = 0;
        dir->replaceLst.push_back( makePPToken("__FILE__") );
        _directiveLst[s] = dir;

        s = "__LINE__";
        dir = new Directive;
        dir->name = "__LINE__"; 
        dir->type = Directive::OBJ;
        dir->paraNum = 0;
        dir->replaceLst.push_back( makePPToken("__LINE__") );
        _directiveLst[s] = dir;

        s = "__DATE__";
        dir = new Directive;
        dir->name = "__DATE__"; 
        dir->type = Directive::OBJ;
        dir->paraNum = 0;
        dir->replaceLst.push_back( makePPToken("__DATE__") );
        _directiveLst[s] = dir;

        s = "__TIME__";
        dir = new Directive;
        dir->name = "__TIME__"; 
        dir->type = Directive::OBJ;
        dir->paraNum = 0;
        dir->replaceLst.push_back( makePPToken("__TIME__") );
        _directiveLst[s] = dir;

        s = "_Pragma";
        dir = new Directive;
        dir->name = "_Pragma"; 
        dir->type = Directive::FUN;
        dir->paraNum = 1;
        dir->paramLst.push_back("a");
        dir->paramMap["a"] = 1;
        _directiveLst[s] = dir;

    }


    vector<PPToken> mergePPToken ( PPToken& p1, PPToken& p2)
    {
        vector<int> mergedUNC;
        mergedUNC.insert(mergedUNC.end(), p1.data.begin(), p1.data.end());
        mergedUNC.insert(mergedUNC.end(), p2.data.begin(), p2.data.end());

        PPTokenizer tokenizer;
        tokenizer.parse( mergedUNC );
  
        // skip the last EOF 
        //
        if ( tokenizer._elst.size() > 0)
        {
           tokenizer._elst.pop_back(); 
        }

        return tokenizer._elst;
    }

    PPToken stringize( list<PPToken>& ll )
    {
        vector<int> mergedCodes;
        list<PPToken> tmp1, tmp2, tmp3;
        bool bStripe = true; 
        for ( list<PPToken>::iterator lt = ll.begin(); lt != ll.end() ; ++lt )
        {
            if (lt->type == PP_WHITESPACE && bStripe == true)
            {
                continue; 
            }
            else
            {
                tmp1.push_back( *lt );
                bStripe = false;
            }
        }

        bStripe = true;
        for ( list<PPToken>::reverse_iterator lt = tmp1.rbegin(); lt != tmp1.rend() ; ++lt )
        {
            if (lt->type == PP_WHITESPACE && bStripe == true)
            {
                continue; 
            }
            else
            {
                tmp2.push_front( *lt );
                bStripe = false;
            }
        }

        bool prevWhiteSpace = false;
        for ( list<PPToken>::iterator lt = tmp2.begin(); lt != tmp2.end() ; ++lt )
        {
            if (lt->type == PP_WHITESPACE)
            {
                if (prevWhiteSpace == true)
                {
                    continue;
                } 
                else
                {
                    tmp3.push_back( *lt );
                    prevWhiteSpace = true;
                }
            }
            else
            {
                tmp3.push_back( *lt );
                prevWhiteSpace = false;
            }
        }


        //-----
        // merge all tmp2 elements to a signle code list 
        //
        vector<int> tmpCode;
        tmpCode.push_back('"');
        for (list<PPToken>::iterator lt = tmp3.begin(); lt != tmp3.end() ; ++lt)
        {

            if (lt->type == PP_WHITESPACE)
            {
                tmpCode.push_back( ' ' );
                continue;
            }
            for (unsigned i=0; i<lt->data.size(); i++)
            {
                if (lt->data[i] == '"') 
                {
                    tmpCode.push_back('\\');
                }
                else if ( lt->data[i] == '\\')
                {
                    if ( i<lt->data.size()-1 &&  isDigit(lt->data[i+1]) )
                    {
                        tmpCode.push_back('\\');
                    }
                }
                tmpCode.push_back( lt->data[i] );
            }
        }
        tmpCode.push_back('"');

        string utf8str = UTF8Encoder::encode(tmpCode);

        return PPToken(PP_STRING_LITERAL, tmpCode, utf8str);
    }



    list<PPToken> trimTail(list<PPToken> tokens)
    {
        list<PPToken>::reverse_iterator rit = tokens.rbegin();
        while (rit != tokens.rend())
        {
            if (rit->type == PP_WHITESPACE)
            {
                rit++;
                tokens.pop_back();
            }
            else break;
        }

        return tokens;
    }


    list<PPToken> trimBegin(list<PPToken> tokens)
    {
        list<PPToken>::iterator it = tokens.begin(); 
        while (it != tokens.end())
        {
            if (it->type == PP_WHITESPACE)
            {
                it++;
                tokens.pop_front();
            }
            else break;
        }

        return tokens;
    }


    list<PPToken> trim( list<PPToken> tokens )
    {
        list<PPToken>::iterator it = tokens.begin(); 
        while (it != tokens.end())
        {
            if (it->type == PP_WHITESPACE)
            {
                it++;
                tokens.pop_front();
            }
            else break;
        }

        list<PPToken>::reverse_iterator rit = tokens.rbegin();
        while (rit != tokens.rend())
        {
            if (rit->type == PP_WHITESPACE)
            {
                rit++;
                tokens.pop_back();
            }
            else break;
        }

        return tokens;
    }


    vector<PPToken> trim( vector<PPToken> tokens )
    {
        list<PPToken> tmp;
        tmp.insert(tmp.end(), tokens.begin(), tokens.end());
        list<PPToken> tmp2 = trim( tmp );

        vector<PPToken> v;
        v.insert(v.end(), tmp2.begin(), tmp2.end());

        return v;
    }


    list<PPToken> trimAll( list<PPToken> tokens )
    {
        list<PPToken>::iterator it = tokens.begin();


        while (it != tokens.end())
        {
            if ( it->type == PP_WHITESPACE )
            {
                it = tokens.erase(it);
                continue;
            }
            it++;
        }

        return tokens;
    }


    vector<PPToken> trimAll( vector<PPToken> tokens )
    { 
        list<PPToken> tmpl(tokens.begin(), tokens.end()); 

        tmpl = trimAll( tmpl );
        
        return vector<PPToken>(tmpl.begin(), tmpl.end());
    }


    list<PPToken> trimForConcat ( list<PPToken> tokens )
    {
        // a ## b  ->  a##b
        // # a      ->  #a
        // 
        list<PPToken>  result;    
        bool bPrevConcat = false;
        for ( list<PPToken>::iterator it = tokens.begin(); it != tokens.end() ; ++it)
        {
            if ( isConcatOp (it->utf8str) )
            {
                result = trimTail(result);
                bPrevConcat = true;
            }
            else if (isDirectiveStartOp(it->utf8str))
            {
                bPrevConcat = true;
            }
            else 
            {
                if (it->type == PP_WHITESPACE || it->type == PP_NEWLINE)
                {
                    if (bPrevConcat == true)
                    {
                        continue;
                    }
                }
                else
                {
                    bPrevConcat = false;
                }
                    
            }
            result.push_back( *it );
        }

        return result;
    }

    vector<PPToken> trimForConcat ( vector<PPToken> tokens )
    {
        list<PPToken> tmp( tokens.begin(), tokens.end() );
        list<PPToken> tmp2 = trimForConcat( tmp );
        
        return vector<PPToken>(tmp2.begin(), tmp2.end());
    }


    list<PPToken> inheritDirective( list<PPToken> tokens, Directive* dir)
    {
        for ( list<PPToken>::iterator it = tokens.begin(); it != tokens.end(); ++it)
        {
            it->blackLst.insert( dir );
        }

        return tokens;
    }


    list<PPToken> replaceText( list<PPToken> tokens )
    {
        //-----
        // debug code
        //
        cerr << "------ replace Text";
        for (list<PPToken>::iterator it = tokens.begin(); it!=tokens.end() ; ++it)
        {
            cerr << "-" <<  it->utf8str;
        }
        cerr << endl;


        list<PPToken> result;
        list<PPToken>::iterator ppit; 
        while (tokens.size() != 0)
        { 
            ppit = tokens.begin();
           
            if (ppit->type == PP_IDENTIFIER) 
            {
                map<string, Directive*>::iterator dit = _directiveLst.find( ppit->utf8str );

                if (dit != _directiveLst.end() &&
                    ppit->blackLst.find( dit->second ) == ppit->blackLst.end())
                {
                    // macro replace
                    PPToken curFunc = *ppit;
                    Directive* dir = dit->second;
                    if (dir->type == Directive::FUN)
                    {
                        //-----
                        // make sure the function is valid with a '(' behind.
                        // 
                        list<PPToken>::iterator quoteIt = ppit;
                        quoteIt++;
                        while (quoteIt != tokens.end())
                        {
                            if (quoteIt->type == PP_WHITESPACE)
                                quoteIt++;
                            else
                                break;
                        }
                        if (quoteIt == tokens.end() || quoteIt->utf8str != "(")
                        {
                            result.push_back( *ppit );
                            tokens.pop_front();
                            continue;
                        }

                        //-----
                        // collect arguments
                        //
                        vector< list<PPToken> > args;
                        int argIdx = -1;
                        int quoteStack = 0;
                        tokens.pop_front();
                        while (tokens.size() != 0)
                        {
                            ppit = tokens.begin();
                            if (ppit->type == PP_WHITESPACE)    
                            {
                                if (quoteStack > 0)
                                {
                                    args[argIdx].push_back( *ppit );
                                }
                            }
                            else if (ppit->utf8str == "(")
                            {
                                quoteStack++;
                                if (quoteStack == 1)
                                {
                                    argIdx++;
                                    args.push_back( list<PPToken>() );
                                }
                                else
                                {
                                    args[argIdx].push_back( *ppit );
                                }
                            }
                            else if (ppit->utf8str == ")")
                            {
                                quoteStack--;
                                if (quoteStack != 0)
                                {
                                    args[argIdx].push_back( *ppit );
                                }
                                else
                                {
                                    tokens.pop_front();
                                    break;
                                }
                            }
                            else if (ppit->utf8str == ",")
                            {
                                if (quoteStack == 1)
                                {
                                    argIdx++;
                                    args.push_back( list<PPToken>() );
                                }
                                else
                                {
                                    args[argIdx].push_back( *ppit );
                                }
                            }
                            else
                            {
                                args[argIdx].push_back( *ppit );
                            }

                            tokens.pop_front();
                        }

                        if (quoteStack != 0)
                        {
                            throw DirectiveHandlerException("Unbalanced quotes");
                        }

                        // for (unsigned i=0; i<args.size(); ++i)
                        // {
                        //     args[i] = trim( args[i] );
                        // }

                        if (dir->name == "_Pragma" && args.size()==1 && args[0].front().utf8str == "\"once\"")
                        {
                            _pragmaOnce = true;
                            continue;
                        }

                        //-----
                        // scan through all the replacement list
                        // and put each replacement token back to the scan list
                        //
                        for (unsigned i=dir->replaceLst.size() ; i>0; i--)
                        {
                            PPToken p = dir->replaceLst[i-1];

                            if (isConcatOp(p.utf8str))
                            {
                                continue;
                            }

                            map<string,int>::iterator pmit = dir->paramMap.find( p.utf8str );
                            if (pmit != dir->paramMap.end() || p.utf8str == "__VA_ARGS__")
                            {
                                list<PPToken> myArg;   // arguments of this parameter

                                if (pmit != dir->paramMap.end())
                                {
                                    int idx = pmit->second; 
                                    myArg = trim ( args[idx] );
                                }
                                else   // __VA_ARGS__
                                {
                                    // combine the corresponding arguments, includeing commas as the new PPTokens list
                                    // 1. __VA_ARGS__ should be the last param
                                    //
                                    vector<int> v;
                                    v.push_back(',');
                                    PPToken comma(PP_OP, v, string(","));
                                    unsigned idx = dir->paramLst.size() - 1; 
                                    for (unsigned i = idx; i<args.size() ; i++)
                                    {
                                        myArg.insert(myArg.end(), args[i].begin(), args[i].end());
                                        if ( i != args.size() -1)
                                        {
                                            myArg.insert(myArg.end(), comma);
                                        }
                                    }
                                }
                                
                                if (i >= 2 && isDirectiveStartOp(dir->replaceLst[i-2].utf8str))
                                {
                                    // no need to replace, and stringize the token
                                    PPToken ps = stringize( myArg );
                                    tokens.insert(tokens.begin(), ps);
                                    i--; // skip the "#" token
                                }
                                else if ( i<dir->replaceLst.size()-1 && isConcatOp(dir->replaceLst[i].utf8str))
                                {
                                    PPToken pr = *(tokens.begin());
                                    PPToken pl = (myArg.size() > 0) ? myArg.back() : PPToken(PP_PLACEMARKER);
                                    tokens.pop_front();

                                    list<PPToken> tmp = myArg;
                                    if (tmp.size() > 0)
                                    {
                                        tmp.pop_back();
                                    }

                                    vector<PPToken> tmpv = mergePPToken(pl, pr);
                                    tmp.insert(tmp.end(), tmpv.begin(), tmpv.end());

                                    tokens.insert(tokens.begin(), tmp.begin(), tmp.end());
                                }
                                else if ( i>= 2 && isConcatOp(dir->replaceLst[i-2].utf8str))
                                {
                                    if (myArg.size() == 0)
                                    {
                                        tokens.insert( tokens.begin(), PPToken(PP_PLACEMARKER) );
                                    }
                                    else
                                    {
                                        tokens.insert(tokens.begin(), myArg.begin(), myArg.end());
                                    }
                                    i--; // skip concat
                                }
                                else
                                {
                                    // recursive replace arguments
                                    list<PPToken> rarg = replaceText( myArg );

                                    rarg = inheritDirective( rarg , dir);
                                    set<Directive*>::iterator sit;
                                    for ( sit = curFunc.blackLst.begin(); sit != curFunc.blackLst.end(); sit++)
                                    {
                                        rarg = inheritDirective( rarg , *sit );
                                    }

                                    // put the corresponding argument here
                                    tokens.insert(tokens.begin(), rarg.begin(), rarg.end());
                                }
                            }
                            else // not parameter
                            {
                                if ( i<dir->replaceLst.size()-1 && isConcatOp(dir->replaceLst[i].utf8str))
                                {
                                    PPToken pr = *(tokens.begin());
                                    PPToken pl = p;
                                    tokens.pop_front();

                                    vector<PPToken> tmpv = mergePPToken(pl, pr);
                                    tokens.insert(tokens.begin(), tmpv.begin(), tmpv.end());
                                }
                                else if ( i>= 2 && isConcatOp(dir->replaceLst[i-2].utf8str))
                                {
                                    tokens.insert(tokens.begin(), p);
                                    i--; // skip concat
                                }
                                else 
                                {
                                    p.blackLst.insert( curFunc.blackLst.begin(), curFunc.blackLst.end() );
                                    p.blackLst.insert( dir );
                                    tokens.insert(tokens.begin(), p);
                                }
                            }
                        }
                        continue;
                    }
                    else  // Directive::OBJ
                    {
                        PPToken po = *ppit;

                        tokens.pop_front();  // remove the current token, 
                        for (unsigned i=dir->replaceLst.size(); i>0; i--)
                        {
                            PPToken p = dir->replaceLst[i-1];
                            p.lineNo = po.lineNo;

                            if (dir->name == "__LINE__") // should be only one token in replaceLst
                            {
                                tokens.insert(tokens.begin(), makePPToken(po.lineNo, po.lineNo));
                            }
                            else if (dir->name == "_Pragma")
                            {
                                if (p.utf8str == "\"once\"")
                                {
                                    _pragmaOnce = true;
                                }
                            }
                            else if ( i<dir->replaceLst.size()-1 && isConcatOp(dir->replaceLst[i].utf8str))
                            {
                                PPToken pr = *(tokens.begin());
                                PPToken pl = p;
                                tokens.pop_front();

                                vector<PPToken> tmpv = mergePPToken(pl, pr);
                                tokens.insert(tokens.begin(), tmpv.begin(), tmpv.end());
                            }
                            else if ( i>= 2 && isConcatOp(dir->replaceLst[i-2].utf8str))
                            {
                                tokens.push_front( p );
                                i--; // skip concat
                            }
                            else
                            {
                                p.blackLst.insert( curFunc.blackLst.begin(), curFunc.blackLst.end() );
                                p.blackLst.insert( dir );
                                tokens.push_front( p );
                            }
                        }
                        continue;
                    }
                }
                else  // normal identifier
                {
                    result.push_back( *ppit );

                    if (ppit->utf8str == "defined")   // special handling for ctrl statement
                    {
                        tokens.pop_front();

                        // skip the next ID or next "(" "ID"
                        //
                        // 0-> ( -> 1 -> id -> 2
                        //  -> id -> 2
                        //  anything else -> 3
                        //
                        list<PPToken>::iterator tit;
                        int state = 0;
                        while (tokens.size() > 0 && state < 2)
                        {
                            tit = tokens.begin();
                            if (tit->type == PP_WHITESPACE)
                            {
                                tokens.pop_front();
                                continue;
                            }
                            else 
                            {
                                switch (state)
                                {
                                    case 0:
                                        if (tit->utf8str == "(")
                                        {
                                            result.push_back( *tit );
                                            tokens.pop_front();
                                            state = 1;
                                        }
                                        else if (tit->type == PP_IDENTIFIER)
                                        {
                                            result.push_back( *tit );
                                            tokens.pop_front();
                                            state = 2;
                                        }
                                        else
                                        {
                                            state = 3;
                                        }
                                        break;
                                    case 1:
                                        if (tit->type == PP_IDENTIFIER)
                                        {
                                            result.push_back( *tit );
                                            tokens.pop_front();
                                            state = 2;
                                        }
                                        else
                                        {
                                            state = 3;
                                        }
                                        break;
                                    default:
                                        state = 3;
                                        break;
                                }
                            }
                        }
                    }
                    else
                    {
                        tokens.pop_front();
                    }
                    continue;
                }
            }
            else
            {
                result.push_back( *ppit );
                tokens.pop_front();
            }
        }
        return result;
    }


    //
    // consumes all text lines  until the next directive start
    //
    bool processTextLines(MacroPPToken& macro)
    {

        list<PPToken> result = replaceText( macro.pplst );
        _result.insert(_result.end(), result.begin(), result.end());

        return true;
    }


    bool processDirectiveDefine(MacroPPToken& macro)
    {
        Directive* dir = new Directive;
        //-----
        // 0 -> # -> 1 -> define -> 2 -> id -> 3 -> !( -> 5 -> replacelst
        //                                       -> (  -> 4 -> paramList -> )  -> 5 -> replacelst
        //
        list<PPToken>::iterator ppit;
        // int state = 0;
        int state = 2;
        int argIdx = 0;
        int state4_subState = 0;  // 0, looking for id;  1, looking for comma or ')'

        while (macro.pplst.size() > 0)
        {
            ppit = macro.pplst.begin();

            if (ppit->type == PP_WHITESPACE)
            {
                // skip whitespace if it is not in replace list
                //
                if (state == 5)
                {
                    dir->replaceLst.push_back( *ppit ); 
                }
                else if (state == 3)
                {
                    // obj, parse parameter
                    dir->type = Directive::OBJ;
                    state = 5;
                }
            }
            else
            {
                switch (state)
                {
                    case 0:
                        if (isDirectiveStartOp(ppit->utf8str))
                        {
                            state = 1;
                        }
                        break;
                    case 1:
                        if (ppit->utf8str == "define")
                        {
                            state = 2;
                        }
                        break;
                    case 2:
                        if (ppit->type == PP_IDENTIFIER)
                        {
                            state = 3;
                            dir->name = ppit->utf8str;
                        }
                        break;
                    case 3:
                        if (ppit->type == PP_OP && ppit->utf8str == "(")
                        {
                            dir->type = Directive::FUN;
                            state = 4;
                        }
                        else 
                        {
                            dir->type = Directive::OBJ;
                            state = 5;
                            continue;
                        }
                        break;
                    case 4:
                        while (ppit->utf8str != ")")
                        {
                            if (ppit->type != PP_WHITESPACE)
                            {
                                if (state4_subState == 0 && ppit->type != PP_IDENTIFIER && ppit->utf8str != "...")
                                {
                                    throw DirectiveHandlerException("Bad directive param");
                                }
                                else if (state4_subState == 1 && ppit->utf8str != ",")
                                {
                                    throw DirectiveHandlerException("Bad directive param");
                                }
                            }

                            if (ppit->type == PP_IDENTIFIER)
                            {
                                state4_subState = 1;
                                dir->paramMap[ ppit->utf8str ] = argIdx;
                                dir->paramLst.push_back( ppit->utf8str );
                                argIdx++;
                            }
                            else if (ppit->type == PP_OP)
                            {
                                if (ppit->utf8str == ",")
                                {
                                    // do nothing
                                    state4_subState = 0;
                                }
                                else if (ppit->utf8str == "...")
                                {
                                    dir->paramMap[ ppit->utf8str ] = argIdx;
                                    dir->paramLst.push_back( ppit->utf8str );
                                    argIdx++;
                                }
                            }
                            else if (ppit->type == PP_WHITESPACE)
                            {
                                ;
                            }
                            else
                            {
                                throw DirectiveHandlerException("Bad directive type");
                            }
                            macro.pplst.pop_front();
                            ppit = macro.pplst.begin();
                        }

                        state = 5;
                        break;
                    case 5:
                        dir->replaceLst.push_back( *ppit ); 
                        break;
                    default:
                        throw DirectiveHandlerException("Bad define syntax");
                        break;
                }
            }

            macro.pplst.pop_front();
        }


        dir->replaceLst = trimForConcat( dir->replaceLst );
        dir->replaceLst = trim( dir->replaceLst );

        if (checkValidDirective(dir) == false)
        {
            throw DirectiveHandlerException("Bad define syntax");
        }

        _directiveLst[ dir->name ] = dir;
        return true;
    }


    bool checkValidDirective(Directive* dir)
    {
        //-----
        // check directive correctness
        //
        // 1. __VA_ARGS__
        // 2. ## should have two arguments
        // 3. #  shold follow parameter
        //

        if (dir->name == "__VA_ARGS__")
        {
            return false;
        }

        bool bVarArgs = false;
        for (unsigned i=0; i<dir->paramLst.size(); i++)
        {
            if (dir->paramLst[i] == "...")
            {
                if (i == dir->paramLst.size()-1)
                {
                    // valid
                    bVarArgs = true;
                }
                else
                {
                    return false;
                }
            }
        }
        for (unsigned i=0; i<dir->replaceLst.size(); i++)
        {
            if (dir->replaceLst[i].utf8str == "__VA_ARGS__" && bVarArgs == false)
            {
                return false;
            }
        }
        
        // 2.  ## should have two operands 
        //
        if ( dir->replaceLst.size() > 0 )
        {
            if (isConcatOp(dir->replaceLst[0].utf8str))
            {
                return false;
            }
            if (isConcatOp(dir->replaceLst[dir->replaceLst.size()-1].utf8str))
            {
                return false;
            }
        }

        // 3. in function-like macro, # should be followd by a parameter
        // 
        if (dir->type == Directive::FUN)
        {
            for (unsigned i=0; i<dir->replaceLst.size(); i++)
            {
                if (isDirectiveStartOp(dir->replaceLst[i].utf8str))
                {
                    if (i == dir->replaceLst.size()-1)
                    {
                        return false;
                    }
                    map<string,int>::iterator mit = dir->paramMap.find( dir->replaceLst[i+1].utf8str );
                    if ( mit == dir->paramMap.end() && dir->replaceLst[i+1].utf8str != "__VA_ARGS__") 
                    {
                        return false;
                    }
                }
            }
            
        }


        // 4. check redefine
        //  
        map<string, Directive*>::iterator dit = _directiveLst.find( dir->name ); 
        if (dit != _directiveLst.end())
        {
            Directive* dir0 = dit->second;

            if (dir0->type != dir->type)
            {
                return false;
            }

            if (dir0->paramLst.size() != dir->paramLst.size())
            {
                return false;
            }
            else
            {
                for (unsigned i=0 ; i<dir->paramLst.size(); i++)
                {
                    if (dir->paramLst[i] != dir0->paramLst[i]) 
                    {
                        return false;
                    }
                }
            }

            
            list<PPToken> dir0_tokens( dir0->replaceLst.begin(), dir0->replaceLst.end());
            list<PPToken> dir_tokens( dir->replaceLst.begin(), dir->replaceLst.end() ); 

            dir0_tokens = trim(dir0_tokens);
            dir_tokens = trim(dir_tokens);

            if (dir0_tokens.front().utf8str == "(")
            {
                if (dir0_tokens.back().utf8str == ")")
                {
                    dir0_tokens.pop_front();
                    dir0_tokens.pop_back();
                    dir0_tokens = trim (dir0_tokens);
                }
            }

            if (dir_tokens.front().utf8str == "(")
            {
                if (dir_tokens.back().utf8str == ")")
                {
                    dir_tokens.pop_front();
                    dir_tokens.pop_back();
                    dir_tokens = trim (dir_tokens);
                }
            }

            if (dir0_tokens.size() != dir_tokens.size())
            {
                return false;
            }
            else
            { 
                list<PPToken>::iterator it0, it;
                for (it0=dir0_tokens.begin(), it=dir_tokens.begin() ; it0!=dir0_tokens.end() && it!=dir_tokens.end(); it0++, it++)
                {
                    if (it0->type != it->type)
                        return false;

                    if (it0->utf8str != it->utf8str)
                        return false;
                }
            }
        }

        return true;
    }


    bool processDirectiveUndefine (MacroPPToken& macro)
    {
        list<PPToken>::iterator ppit;
        // int state = 0;
        int state = 2;
        while (macro.pplst.size() > 0)
        {
            ppit = macro.pplst.begin();

            if (ppit->type == PP_WHITESPACE)
            {
                // skip whitespace
            }
            else
            {
                switch (state)
                {
                    case 0:
                        if (isDirectiveStartOp(ppit->utf8str))
                        {
                            state = 1;
                        }
                        break;
                    case 1:
                        if (ppit->utf8str == "undef")
                        {
                            state = 2;
                        }
                        break;
                    case 2:
                        if (ppit->type == PP_IDENTIFIER)
                        {
                            state = 3;
                            map<string, Directive*>::iterator mit = _directiveLst.find(ppit->utf8str);
                            _directiveLst.erase( mit );
                        }
                        else
                        {
                            throw DirectiveHandlerException("Bad undef argument");
                        }
                        break;
                    default:
                        throw DirectiveHandlerException("Bad undef syntax");
                        break;
                }
            }

            macro.pplst.pop_front();
        }

        return true;
    }


    bool evaluate( MacroPPToken& mt)
    {
        vector<PPToken> vec;

        if (mt.type == IF || mt.type == ELIF)
        {
            list<PPToken> newLst = replaceText( mt.pplst );
            vec.insert(vec.end(), newLst.begin(), newLst.end());
        }
        else
        {
            vec.insert(vec.end(), mt.pplst.begin(), mt.pplst.end());
        }
        PostTokenizer postTokenizer(vec);
        postTokenizer.parse();

        if (mt.type == IF || mt.type == ELIF)
        {
            PPCtrlExprEvaluator peval(postTokenizer._tokens.begin(), postTokenizer._tokens.end());
            peval._directiveLst = this->_directiveLst;
            return peval.startEval();
        }
        else if (mt.type == IFDEF)
        {
            if (postTokenizer._tokens.size() != 1 || postTokenizer._tokens[0].type != PT_SIMPLE)
            {
                throw DirectiveHandlerException("Bad IFDEF directive expr");
            }

            map<string, Directive*>::iterator dit = _directiveLst.find( postTokenizer._tokens[0].source );
            if (dit == _directiveLst.end())
            {
                return false; 
            }
            else
            {
                return true;
            }
        }
        else if (mt.type == IFNDEF)
        {
            if (postTokenizer._tokens.size() != 1 || postTokenizer._tokens[0].type != PT_SIMPLE)
            {
                throw DirectiveHandlerException("Bad IFDEF directive expr");
            }

            map<string, Directive*>::iterator dit = _directiveLst.find( postTokenizer._tokens[0].source );
            if (dit == _directiveLst.end())
            {
                return true; 
            }
            else
            {
                return false;
            }
        }
        else 
        {
            throw DirectiveHandlerException("Expect if-group directives");
        }

        return true;
    }


    void processDirectiveError( MacroPPToken& mt )
    {
        list<PPToken> tokens;
        list<PPToken>::iterator ppit;
        bool prevSpace = false;

        // merge multiple space to 1 space
        //
        while (mt.pplst.size() > 0)
        {
            ppit = mt.pplst.begin();

            if (ppit->type == PP_WHITESPACE)
            {
                if (prevSpace)
                {
                    mt.pplst.pop_front();
                    continue;
                }
            }
            tokens.push_back( *ppit );
            mt.pplst.pop_front();
        }

        PPToken pt = stringize( tokens );
        throw DirectiveHandlerException(pt.utf8str.c_str());
    }


    void processDirectiveInclude( list<MacroPPToken> &macroTokens, list<MacroPPToken>::iterator& it )
    {
        //-----
        // search for the include path
        //
        list<PPToken> lst0 = trim( it->pplst );
        list<PPToken> lst = replaceText( lst0 );

        if (lst.size() != 1)
        {
            throw DirectiveHandlerException("Bad include file, extra tokens");
        }

        //int incType = 0;
        string incFile = lst.begin()->utf8str;
        string inc;

        if (incFile[0]=='"' && incFile[incFile.size()-1] == '"')
        {
            inc = incFile.substr(1, incFile.size() - 2);
            //incType = 0;
        }
        else if (incFile[0]=='<' && incFile[incFile.size()-1] == '>')
        {
            inc = incFile.substr(1, incFile.size() - 2);
            //incType = 1;
        }
        else
        {
            throw DirectiveHandlerException("Bad include header name, neither <> nor \"\"");
        }

        //-----
        // rebuild the new srcfile name
        //
        string nextf;
        size_t slashPos = _srcfile.rfind("/");
        if (slashPos == string::npos)
        {
            nextf = inc;
        }
        else
        {
            nextf = _srcfile.substr(0, slashPos+1);
            nextf += inc;
        }

        //-----
        //  check if file exists
        // 
        PA5FileId fileid; 
        bool file_exist = PA5GetFileId(nextf, fileid);
        if (file_exist == false)
        {
            file_exist = PA5GetFileId(inc, fileid);
            if (file_exist == false)
            {
                string msg = "Cannot file include file : ";
                msg += inc;
                throw DirectiveHandlerException(msg.c_str());
            }
            nextf = inc;
        }  

        //-----
        //  parse included file to pptokens 
        //
        ifstream in(nextf);
        ostringstream oss;
        oss << in.rdbuf();
        string input = oss.str();
    
        vector<int> uncTokens;
        int code_unit;
        UTF8Decoder utf8Decoder(&input);
        while ((code_unit = utf8Decoder.nextCode()) > 0)
        {
            uncTokens.push_back(code_unit);
        }
        if (uncTokens.size()>0 && uncTokens[uncTokens.size()-1]!='\n')
        {
            uncTokens.push_back('\n');
        }
        PPTokenizer ppTokenizer;
        ppTokenizer.parse(uncTokens);
   
        //-----
        // generate MacroPPToken list for the include file
        //
        DirectiveHandler dir0(nextf, ppTokenizer._elst);
        dir0.createMacroTokens();

        list<MacroPPToken> mlst = dir0._list;

        dir0.processDirectives();

        if (dir0._pragmaOnce==false || _includeSet.find(fileid) == _includeSet.end())
        {
            list<MacroPPToken>::iterator insit = it;
            insit++;
            // macroTokens.insert(insit, dir0._list.begin(), dir0._list.end());
            mlst.back().pplst.pop_back();   // pop eof
            macroTokens.insert(insit, mlst.begin(), mlst.end());
            it = macroTokens.erase( it );
            
            _includeSet.insert(fileid);
        }
        else
        {
            it = macroTokens.erase( it );
        }

        // dir0._list.back().pplst.pop_back();  // pop eof

        // list<MacroPPToken>::iterator insit = it;
        // insit++;
        // macroTokens.insert(insit, dir0._list.begin(), dir0._list.end());
        // it = macroTokens.erase( it );
    }


    void processDirectiveIf( list<MacroPPToken> &macroTokens, list<MacroPPToken>::iterator& it )
    {
        //----
        //   0 -> if-group -> 1 -> elif -> 2
        //                      -> else -> 3
        //                      -> endif -> 4
        //
        // 
        int state = 0;
        bool condition = false;
        bool skip = false;
        bool elseFound = false;

        while (it != macroTokens.end())
        {
            switch (state)
            {
                case 0:
                    if (it->type == IF || it->type == IFDEF || it->type == IFNDEF)
                    {
                        condition = evaluate ( *it );
                    }

                    // it will automaticall move to next token
                    it = macroTokens.erase( it );
                    skip = condition ? false : true;
                    state = 1;
                    break;

                case 1:
                    if (it->type == IF || it->type == IFDEF || it->type == IFNDEF)
                    {
                        if (skip)
                        {
                            int ifdepth = 0; 
                            int elseFoundi = -1; 
                            while (it != macroTokens.end()) 
                            {

                                if (it->type == IF || it->type == IFDEF || it->type == IFNDEF)
                                {
                                    it = macroTokens.erase( it );
                                    ifdepth++;
                                    continue;
                                }
                                else if (it->type == ELIF)
                                {
                                    if (elseFoundi == ifdepth)
                                    {
                                        throw DirectiveHandlerException("elif out of order");
                                    }
                                    it = macroTokens.erase( it );
                                    continue;
                                }
                                else if (it->type == ELSE)
                                {
                                    elseFoundi = ifdepth;
                                    it = macroTokens.erase( it );
                                    continue;
                                }
                                else if (it->type == ENDIF)
                                {
                                    it = macroTokens.erase( it );
                                    ifdepth--;
                                    if (ifdepth == 0)
                                    {
                                        break;
                                    }
                                }
                                else
                                {
                                    it = macroTokens.erase( it );
                                    continue;
                                }
                            }
                        }
                        else
                        {
                            processDirectiveIf( macroTokens, it ); 
                        }
                        state = 1;
                    }
                    else if (it->type == ELIF)
                    {
                        if (condition == true)
                        {
                            skip = true;
                        }
                        else if ( (condition = evaluate( *it )) == true )
                        {
                            skip = false; 
                        }
                        else 
                        {
                            skip = true;
                        }
                        it = macroTokens.erase( it );
                        if (elseFound == true)
                        {
                            throw DirectiveHandlerException("elif out of order");
                        }
                        state = 1;
                    }
                    else if (it->type == ELSE)
                    {
                        if (condition == true)
                        {
                            skip = true;
                        }
                        else 
                        {
                            skip = false;
                        }
                        it = macroTokens.erase( it );
                        elseFound = true;
                        state = 1;
                    }
                    else if (it->type == ENDIF)
                    {
                        macroTokens.erase( it );
                        it = macroTokens.begin();
                        return;
                    }
                    else
                    {
                        if (skip)
                        {
                            it = macroTokens.erase( it );
                        }
                        else
                        {
                            it++;
                        }
                        state = 1;
                    }
                    break;
                case 2:
                    break;
            }
        }

        if (it->type != ENDIF)
        {
            throw DirectiveHandlerException("Expect endif directives");
        }
        else
        {
            macroTokens.erase(it);
        }

        it = macroTokens.begin();

        return;
    }


    void createMacroTokens()
    {
        //-----
        // group tokens to directive macro token  or text line macro token
        //
        vector<PPToken>::iterator it = _pps.begin();        
        while (it != _pps.end())
        {
            PPTokenType type = it->type;
            string str = it->utf8str; 
            if (type == PP_OP && isDirectiveStartOp(str))
            {
                // directive start
                MacroPPToken macro;
                // macro.pplst.push_back( *it );
                it++;
                while (it->type == PP_WHITESPACE)
                {
                    it++;
                }
                if (it->type == PP_IDENTIFIER)
                {
                    map<string, MacroPPTokenType>::const_iterator mit = string2macroPPTokenTypeMap.find(it->utf8str);
                    if (mit == string2macroPPTokenTypeMap.end())
                    {
                        macro.type = INVALID;
                    }
                    else
                    {
                        macro.type = mit->second;
                    }
                    it++;
                }
                else if (it->type == PP_NEWLINE)
                {
                    // do nothing, empty directive is allowed
                    macro.pplst.push_back( *it );
                }
                else
                {
                    macro.type = INVALID;
                    // throw DirectiveHandlerException("Bad directive type");
                }

                while (it->type != PP_NEWLINE)
                {
                    macro.pplst.push_back( *it );
                    it++;
                }
                it++; // skip new line
                _list.push_back( macro );
                continue;
            }
            else if (type == PP_WHITESPACE)
            {
                it++;
                continue;
            }
            else if (type == PP_NEWLINE)
            {
                it++;
                continue;
            }
            else
            {
                bool foundDirective = false;
                MacroPPToken macro; 
                macro.type = TXT;

                // text line
                while (foundDirective == false && it->type != PP_EOF)
                {
                    while (it->type != PP_NEWLINE)
                    {
                        macro.pplst.push_back( *it ); 
                        it++;
                    }

                    // test if the next line is a directive statement
                    //
                    vector<PPToken>::iterator it2 = it;  // it is now newline
                    it2++;
                    while ( it2->type == PP_WHITESPACE || it2->type == PP_NEWLINE )
                    {
                        it2++;
                    }
                    if (it2->type == PP_OP && isDirectiveStartOp(it2->utf8str) )
                    {
                        foundDirective = true;
                    }

                    // macro.pplst.push_back( *it );

                    it ++;
                }

                if (it->type == PP_EOF)
                {
                    macro.pplst.push_back( *it );
                    it++;
                }

                _list.push_back( macro );
                continue;
            }
        }
    }

    
    void processDirectives()
    {
        //----- 
        // loop through all macro lines
        //
        list<MacroPPToken>::iterator lit = _list.begin();

        while (lit != _list.end())
        {
            if (lit->type == IF || lit->type==IFDEF || lit->type == IFNDEF)
            {
                processDirectiveIf( _list, lit ); 
                continue;
            }
            if (lit->type == DEFINE)
            {
                processDirectiveDefine( *lit );
            } 
            else if (lit->type == UNDEF)
            {
                processDirectiveUndefine( *lit );
            }
            else if (lit->type == TXT)
            {
                processTextLines( *lit );
            }
            else if (lit->type == ERROR)
            {
                processDirectiveError( *lit );
            }
            else if (lit->type == INCLUDE)
            {
                processDirectiveInclude( _list, lit );
                continue;
            }
   
            else if (lit->type == INVALID)
            {
                throw DirectiveHandlerException("Bad directive");
            }


            lit = _list.erase( lit );
        }

    }


    void process()
    {

        createMacroTokens();
        processDirectives();
    }


  public:
    string                    _srcfile;
    vector<PostToken>         _pts;
    vector<PPToken>           _pps;
    vector<PPToken>           _result;
    list<MacroPPToken>        _list;
    set<PA5FileId>            _includeSet;

    map<string, Directive*>   _directiveLst;
    bool                      _pragmaOnce;
};

#ifdef PA4
int main()
{
	// TODO:
	// 1. apply your code from PA1 to produce `preprocessing-tokens`
	// 2. "post-tokenize" the `preprocessing-tokens` as described in PA2
	// 3. write them out in the PA2 output format specifed
    try
    {
        ostringstream oss;
        oss << cin.rdbuf();
        string input = oss.str();

        // Decode input stream (UTF-8) to UNC
        vector<int> uncTokens;
        int code_unit;
        UTF8Decoder utf8Decoder(&input);
        while ((code_unit = utf8Decoder.nextCode()) > 0)
        {
            uncTokens.push_back(code_unit);
        }
        if (uncTokens.size()>0 && uncTokens[uncTokens.size()-1]!='\n')
        {
            uncTokens.push_back('\n');
        }

        PPTokenizer ppTokenizer;
        ppTokenizer.parse(uncTokens);

        DirectiveHandler directiveHandler(string(), ppTokenizer._elst);
        directiveHandler.process();
             

        // PA2 start
        PostTokenizer postTokenizer(directiveHandler._result);         
        postTokenizer.parse();

        // // PA3 start
        // vector<PostToken>::iterator it = postTokenizer._tokens.begin(); 
        // vector<PostToken>::iterator lstart=it, lend; 
        // while (it != postTokenizer._tokens.end())
        // {
        //     if (it != lstart)
        //     {
        //         if (it->type == PT_NEWLINE)
        //         {
        //             PPCtrlExprEvaluator peval(lstart, it);
        //             peval.startEval();
        //             it++;
        //             lstart = it;
        //             continue;
        //         }
        //     } 
        //     else
        //     {
        //         if (it->type == PT_NEWLINE)
        //         {
        //             it++;
        //             lstart = it;
        //             continue;
        //         }
        //         else if (it->type == PT_EOF)
        //         {
        //             cout << "eof" << endl;
        //             break;
        //         }
        //     }
        //     it++;
        // }

        // PA2 string concat
        PostToken concatStr;
        bool bPrevStr = false;
        vector<int> strCodes;

        for (unsigned i=0 ; i<postTokenizer._tokens.size() ; i++)
        {
            PostToken pt = postTokenizer._tokens[i];

            if (pt.type == PT_SIMPLE && pt.source == "__VA_ARGS__")
            {
                throw DirectiveHandlerException("\"__VA_ARGS__\" is not valid identifier");
            }

            if (pt.type == PT_LITERAL_ARRAY || pt.type == PT_UD_LITERAL_ARRAY)
            {
                if (bPrevStr==true)
                {
                    concatStr.source += " ";
                    concatStr.source += pt.source;

                    if (concatStr.type == PT_INVALID)
                    {
                        continue;
                    }

                    int code_unit;
                    UTF8Decoder utf8Decoder(&pt.udPrefix);
                    while ((code_unit = utf8Decoder.nextCode()) > 0)
                    {
                        strCodes.push_back(code_unit);
                    }

                    if (concatStr.udSuffix != "" && pt.udSuffix != "" && concatStr.udSuffix != pt.udSuffix)
                    {
                        // error
                        concatStr.type = PT_INVALID;
                        continue;
                    }
                    else
                    {
                        concatStr.udSuffix = (concatStr.udSuffix == "") ? pt.udSuffix : concatStr.udSuffix;
                    }

                    if (concatStr.udSuffix != "")
                    {
                        if (concatStr.udSuffix[0] != '_' || concatStr.type == PT_INVALID)
                        {
                            concatStr.type = PT_INVALID;
                            continue;
                        }
                        else
                        {
                            concatStr.type = PT_UD_LITERAL_ARRAY;
                        }
                    }


                    if (concatStr.ltype != FT_CHAR && pt.ltype != FT_CHAR && concatStr.ltype != pt.ltype)
                    {
                        // different char type
                        concatStr.type = PT_INVALID;
                        continue;
                    } 
                    else
                    {
                        concatStr.ltype = (concatStr.ltype == FT_CHAR) ? pt.ltype : concatStr.ltype;
                    }

                    bPrevStr = true;
                } 
                else
                {
                    concatStr = pt;

                    int code_unit;
                    UTF8Decoder utf8Decoder(&pt.udPrefix);
                    while ((code_unit = utf8Decoder.nextCode()) > 0)
                    {
                        strCodes.push_back(code_unit);
                    }

                    if (concatStr.udSuffix != "" && concatStr.udSuffix[0] != '_')
                    {
                        concatStr.type = PT_INVALID;
                    }
                    bPrevStr = true;
                }
                continue;
            }

            if (bPrevStr == true)
            {
                char* mem;
                int size;
                strCodes.push_back(0);

                if (concatStr.ltype == FT_CHAR || concatStr.ltype == FT_UNSIGNED_CHAR || concatStr.ltype == FT_SIGNED_CHAR)
                {
                    string es = UTF8Encoder::encode(strCodes);
                    mem = new char[es.size()];
                    memcpy(mem, es.c_str(), es.size());
                    size = es.size();
                }
                else if (concatStr.ltype == FT_CHAR16_T)
                {
                    vector<short> utf16_codes = UTF16Encoder::encode( strCodes );
                    char16_t* data = new char16_t[utf16_codes.size()];
                    for (unsigned int i=0; i<utf16_codes.size(); ++i)
                    {
                        data[i] = utf16_codes[i];
                    }
                    mem = (char*)data;
                    size = utf16_codes.size();
                }
                else if (concatStr.ltype == FT_CHAR32_T)
                {
                    char32_t* data = new char32_t[strCodes.size()];
                    for (unsigned int i=0; i<strCodes.size(); ++i)
                    {
                        data[i] = strCodes[i];
                    }
                    mem = (char*)data;
                    size = strCodes.size();
                }
                else if (concatStr.ltype == FT_WCHAR_T)
                {
                    wchar_t* data = new wchar_t[strCodes.size()];
                    for (unsigned int i=0; i<strCodes.size(); ++i)
                    {
                        data[i] = strCodes[i];
                    }
                    mem = (char*)data;
                    size = strCodes.size();
                }

                concatStr.data = mem;
                concatStr.size = size;
                concatStr.emit();
                bPrevStr = false;
                strCodes.clear();
            }
            pt.emit();
        }  // end string concat

    }
    catch (exception& e)
    {
        cerr << "ERROR: " << e.what() << endl;
        return EXIT_FAILURE;
    }
}
#endif
