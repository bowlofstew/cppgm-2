
#ifndef __PPROC_H__
#define __PPROC_H__

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>
#include <cstdio>



//-----
// This is a smple preprocessor, which can be inheritted to handle your own tokens.
//   input  is a std::string 
//   output is a "PPToken" vector
//
// The major state machine in "tokenize()" function will try to split all character in
// several catagories. By default it handles number format "1e-5"  
//
enum PPTokenType {
    PP_NA = 0,
    PP_ID = 1,     // a, a12 
    PP_NUM = 2,    // 1, 123, 1.2, 1e5, 1E-8
    PP_STR = 4,    // "a" 'b' "aaa" 'bbb'
    PP_LE = 8,     // \n
    PP_OP = 16,    // + , - , *, /, ...
    PP_SPACE = 32  // \t, ' '
};



class PPToken {
  public:
    std::string  str;
    PPTokenType  type;
    unsigned int line;

    PPToken() {
        type = PP_NA;
        line = -1;
    }    

    PPToken(const std::string s, PPTokenType t, int l)
        : str(s), type(t), line(l)
    {
    }

    void dump() {
        std::cerr << toStr();
    }

    std::string toStr() {
        std::stringstream ss;
        if (str == "\n") {
            ss << "LINEEND " << line;
        }
        else {
            ss << str << " " << line;
        }
        return ss.str();
    }
};


bool iequal( const std::string& str1, const std::string& str2) {
    if (str1.size() != str2.size()) {
        return false;
    }
    for (std::string::const_iterator c1 = str1.begin(), c2 = str2.begin(); c1 != str1.end(); ++c1, ++c2) {
        if (tolower(*c1) != tolower(*c2)) {
            return false;
        }
    }
    return true;
}






class TxtPreprocessorException : public std::exception
{
  public:
    TxtPreprocessorException(const char* msg)
        : _errMsg(msg)
    {
    }

    virtual ~TxtPreprocessorException() throw()
    {
    }

    virtual const char* what() const throw()
    {
        return _errMsg.c_str();
    }

  private:
    std::string _errMsg;
 
};


class TxtPreprocessor {
  public:
    TxtPreprocessor() {
    } 

    virtual ~TxtPreprocessor() {
    } 


    //-----
    // template pattern
    //
    void process (const std::string& inStr) 
    {
        tokens = tokenize(inStr);
        postProcess();
    }

    //-----
    // By default, post process would try to merge "+"/"-" sign in front of a num token.
    // to a signed number token.
    // But this may not be correct if your context has expressions.
    // Ex.  3 + 4 -1
    // Here "+" and "-" does not belong to any number, they are arthimatic operators.
    //
    //
    virtual void postProcess() 
    {
        std::vector<PPToken> tmpTokens; 
        std::string prev = ""; 

        std::vector<PPToken>::iterator  it; 
        for (it = tokens.begin(); it != tokens.end(); it++) 
        {
            if (it->type == PP_NUM) {
                if ( prev == "-" || prev == "+") 
                {
                    tmpTokens.pop_back();
                    PPToken q = *it; 
                    std::string s = "-";
                    s += q.str;
                    q.str = s;
                    tmpTokens.push_back( q );
                }                 
                else {
                    tmpTokens.push_back( *it );
                }
            }
            else 
            {
                tmpTokens.push_back( *it );
            }

            prev = it->str;
        }
        tokens = tmpTokens; 
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
                    if (c=='_' || isChar(c)) {
                        state = 1;
                        t = c;
                    }
                    else if (isDigit(c)) {
                        state = 2;
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
                        state = 5; 
                    } 
                    else if (isSingalCharOp(c)) {
                        t = c;
                        myTokens.push_back( makeToken ( t, PP_OP, line ) );
                        t = "";
                        state = 0;
                    }
                    else if (isStringQuote(c)) {
                        t = c;
                        state = 6;
                    }
                    else if (c=='\\') {
                        state = 0;
                    }
                    else {
                        std::stringstream ss;
                        ss << "Bad token start char " << "\'" << c << "\' at line " << line;
                        throw_pprop_exp( ss.str() );
                    }
                    break;
                case 1:
                    if (isChar(c) || isDigit(c) || c=='_' || c=='.') {
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
                    if (isDigit(c) || c=='.') {
                        state = 2;
                        t += c;
                    }
                    else if (c=='e' || c=='E') {
                        t += c;
                        state = 3;    
                    }
                    else {
                        state = 0;
                        myTokens.push_back( makeToken(t, PP_NUM, line) );
                        t = "";
                        idx--;
                    }
                    break;
                case 3:
                    if (c=='+' || c=='-' || isDigit(c)) {
                        state = 4;
                        t += c;
                    }
                    else {
                        std::stringstream ss;
                        ss << "Bad number format char " << "\'" << c << "\' at line " << line;
                        throw_pprop_exp( ss.str() );
                    }
                    break;
                case 4:
                    if (isDigit(c)) {
                        state = 4;
                        t+= c;
                    }
                    else {
                        state = 0;
                        myTokens.push_back( makeToken(t, PP_NUM, line ) );
                        t = "";
                        idx--;
                    }
                    break;
                case 5:
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
                case 6:
                    //char t0 = t[0];
                    while ( idx<inStr.size() && inStr[idx] != t[0]) {
                        t += inStr[idx];
                        idx++; 
                    }
                    
                    if (idx == inStr.size() ) {
                        std::stringstream ss;
                        ss << "Unmatched string start char " << "\'" << c << "\' at line " << line;
                        throw_pprop_exp( ss.str() );
                    }
                    else {
                        t += inStr[idx];
                        myTokens.push_back( makeToken(t, PP_STR, line) );
                        t = "";
                        state = 0;
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


    virtual bool isSingalCharOp( char c ) {
        if (c==':' || c=='#' || c=='(' || c==')' || c=='+' || c=='*' || c=='-' ||
            c=='=' || c==',' || c=='/' || c=='@' || c=='^' || c=='|' ||
            c=='?' || c==':' || c=='!' || c=='$' || c=='>' || c=='<' || c == '{' || c=='}') 
        {
            return true;
        }
        else
            return false;
    }


    bool isDigit(char c) {
        if ( c >= '0' && c <= '9') {
            return true;
        }
        return false;
    }


    bool isChar(char c) {
        if ( c >= 'a' && c <= 'z') {
            return true;
        }
        else if ( c>= 'A' && c<= 'Z') {
            return true;
        }
        return false;
    }


    virtual bool isCommentStart(char c) {
        if (c == ';')
            return true;
        else
            return false;
    }


    bool isStringQuote(char c) {
        if (c=='\'' || c == '"')
            return true;
        else
            return false;
    }


    bool isSpace(char c) {
        if (c==' ' || c == '\t')
            return true;
        else
            return false;
    }

    bool isLineEnd(char c) {
        if (c=='\n')
            return true;
        else
            return false;
    }


    PPToken  makeToken(std::string s, PPTokenType type, int line) {
        PPToken qt;
        qt.str = s;
        qt.type = type;
        qt.line = line;
        return qt;
    }


    void throw_pprop_exp(std::string msg) 
    {
        throw TxtPreprocessorException( msg.c_str() );
    }

    void dumpTokens() {
        std::vector<PPToken>::iterator it = tokens.begin(); 
        for (; it != tokens.end() ; ++it) {
            it->dump();
            std::cerr << std::endl;
        }
    }

    std::vector<PPToken>     tokens; 
};



class TxtParser {
  public:
    typedef std::vector<PPToken>::iterator PPit;

  public:
    TxtParser() {
        char* turn_on_flag = getenv("QTFDEBUG");
        if (turn_on_flag != NULL) {
            bDebug = true;
        } 
        else {
            bDebug = false;
        }
    }
    ~TxtParser() {}


    PPToken match( PPTokenType type) {
        PPToken t;
        if (cit == eit) {
            std::stringstream ss;
            ss << "No tokens left for matching" << std::endl;
            throw_pprop_exp(ss.str());
        } 
        else if ( cit->type != type ) {
            std::stringstream ss;
            ss << "Unexpected token at line: " << cit->line << std::endl;
            throw_pprop_exp(ss.str());
        }
        else {
            t = *cit;            
            cit++;
        }
        if (bDebug) {
            std::cerr << "MATCHED : " << t.toStr() << std::endl;
        }
        return t;
    } 
    
    
    PPToken match( int com_type) {
        PPToken t;
        if (cit == eit) {
            std::stringstream ss;
            ss << "No tokens left for matching" << std::endl;
            throw_pprop_exp(ss.str());
        } 
        else if ( cit->type & com_type == 0 ) {
            std::stringstream ss;
            ss << "Unexpected token at line: " << cit->line << std::endl;
            throw_pprop_exp(ss.str());
        }
        else {
            t = *cit;            
            cit++;
        }
        if (bDebug) {
            std::cerr << "MATCHED : " << t.toStr() << std::endl;
        }
        return t;
    } 
    
    
    PPToken match( std::string  str) {
        PPToken t;
        if (cit == eit) {
            std::stringstream ss;
            ss << "No tokens left for matching" << std::endl;
            throw_pprop_exp(ss.str());
        } 
        else if ( iequal(cit->str, str)==false ) {
            std::stringstream ss;
            ss << "Unexpected token at line: " << cit->line << std::endl;
            throw_pprop_exp(ss.str());
        }
        else {
            t = *cit;            
            cit++;
        }
        if (bDebug) {
            std::cerr << "MATCHED : " << t.toStr() << std::endl;
        }
        return t;
    } 
    
    PPToken match() {
        PPToken t;
        if (cit == eit) {
            std::stringstream ss;
            ss << "No tokens left for matching" << std::endl;
            throw_pprop_exp(ss.str());
        }
        else {
            t = *cit;
            cit++;
        }
        if (bDebug) {
            std::cerr << "MATCHED : " << t.toStr() << std::endl;
        }
        return t;
    }
    
    void skipLine() {
        while (cit != eit) {
            if (cit->type == PP_LE) {
                cit++;
                break;
            }
            cit++;
        }
    }
    
    void rollback() {
        cit--; 
        return;
    }
    
    
    PPToken  makeToken(std::string s, PPTokenType type, int line) {
        PPToken qt;
        qt.str = s;
        qt.type = type;
        qt.line = line;
        return qt;
    }

    bool iequal( const std::string& str1, const std::string& str2) {
        if (str1.size() != str2.size()) {
            return false;
        }
        for (std::string::const_iterator c1 = str1.begin(), c2 = str2.begin(); c1 != str1.end(); ++c1, ++c2) {
            if (tolower(*c1) != tolower(*c2)) {
                return false;
            }
        }
        return true;
    }

    void throw_pprop_exp(std::string msg) 
    {
        throw TxtPreprocessorException( msg.c_str() );
    }

    PPit cit;
    PPit eit;
   
  protected: 
    bool bDebug;
};




#endif
