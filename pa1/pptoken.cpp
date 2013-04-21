#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <exception>
#include <cstdio>
#include <cstring>

using namespace std;

#include "IPPTokenStream.h"
#include "DebugPPTokenStream.h"
#include "utf8.cpp"

// Translation features you need to implement:
// - utf8 decoder
// - utf8 encoder
// - universal-character-name decoder
// - trigraphs
// - line splicing
// - newline at eof
// - comment striping (can be part of whitespace-sequence)

// EndOfFile: synthetic "character" to represent the end of source file
constexpr int EndOfFile = -1;

// given hex digit character c, return its value
int HexCharToValue(int c)
{
    switch (c)
    {
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    case 'A': return 10;
    case 'a': return 10;
    case 'B': return 11;
    case 'b': return 11;
    case 'C': return 12;
    case 'c': return 12;
    case 'D': return 13;
    case 'd': return 13;
    case 'E': return 14;
    case 'e': return 14;
    case 'F': return 15;
    case 'f': return 15;
    default: throw logic_error("HexCharToValue of nonhex char");
    }
}

// See C++ standard 2.11 Identifiers and Appendix/Annex E.1
const vector<pair<int, int>> AnnexE1_Allowed_RangesSorted =
{
    {0xA8,0xA8},
    {0xAA,0xAA},
    {0xAD,0xAD},
    {0xAF,0xAF},
    {0xB2,0xB5},
    {0xB7,0xBA},
    {0xBC,0xBE},
    {0xC0,0xD6},
    {0xD8,0xF6},
    {0xF8,0xFF},
    {0x100,0x167F},
    {0x1681,0x180D},
    {0x180F,0x1FFF},
    {0x200B,0x200D},
    {0x202A,0x202E},
    {0x203F,0x2040},
    {0x2054,0x2054},
    {0x2060,0x206F},
    {0x2070,0x218F},
    {0x2460,0x24FF},
    {0x2776,0x2793},
    {0x2C00,0x2DFF},
    {0x2E80,0x2FFF},
    {0x3004,0x3007},
    {0x3021,0x302F},
    {0x3031,0x303F},
    {0x3040,0xD7FF},
    {0xF900,0xFD3D},
    {0xFD40,0xFDCF},
    {0xFDF0,0xFE44},
    {0xFE47,0xFFFD},
    {0x10000,0x1FFFD},
    {0x20000,0x2FFFD},
    {0x30000,0x3FFFD},
    {0x40000,0x4FFFD},
    {0x50000,0x5FFFD},
    {0x60000,0x6FFFD},
    {0x70000,0x7FFFD},
    {0x80000,0x8FFFD},
    {0x90000,0x9FFFD},
    {0xA0000,0xAFFFD},
    {0xB0000,0xBFFFD},
    {0xC0000,0xCFFFD},
    {0xD0000,0xDFFFD},
    {0xE0000,0xEFFFD}
};

// See C++ standard 2.11 Identifiers and Appendix/Annex E.2
const vector<pair<int, int>> AnnexE2_DisallowedInitially_RangesSorted =
{
    {0x300,0x36F},
    {0x1DC0,0x1DFF},
    {0x20D0,0x20FF},
    {0xFE20,0xFE2F}
};

// See C++ standard 2.13 Operators and punctuators
const unordered_set<string> Digraph_IdentifierLike_Operators =
{
    "new", "delete", "and", "and_eq", "bitand",
    "bitor", "compl", "not", "not_eq", "or",
    "or_eq", "xor", "xor_eq"
};

// See `simple-escape-sequence` grammar
const unordered_set<int> SimpleEscapeSequence_CodePoints =
{
    '\'', '"', '?', '\\', 'a', 'b', 'f', 'n', 'r', 't', 'v'
};

int trigraphMap(int c)
{
    switch (c)
    {
        case '=': return '#';
        case '/': return '\\';
        case '\'': return '^';
        case '(': return '[';
        case ')': return ']';
        case '!': return '|';
        case '<': return '{';
        case '>': return '}';
        case '-': return '~';
        default : return -1;
    }
}


bool isHex(int c)
{
    if (c >= '0' && c <= '9')
        return true;
    else if (c >= 'a' && c <= 'f')
        return true;
    else if (c >= 'A' && c <= 'F')
        return true;
    else
        return false;
}

bool isOctal(int c)
{
    if (c >= '0' && c <= '7')
        return true;
    else
        return false;
}


class PPTokenizerException : public exception
{
public:
    PPTokenizerException(const char* msg)
        : _errMsg(msg)
    {
    }

    virtual ~PPTokenizerException() throw()
    {
    }

    virtual const char* what() const throw()
    {
        return _errMsg.c_str();
    }

private:
    std::string _errMsg;

};


// Tokenizer
struct PPTokenizer
{
    IPPTokenStream& output;

    // for translation
    vector<int>     _tlst;
    int             _tstate;
    int             _chex;
    int             _vhex;

    PPTokenizer(IPPTokenStream& output)
        : output(output), _tstate(0), _chex(0), _vhex(0)
    {}

    //---------------------------------
    // trigraph, UCN, line-splicing 
    //
    int translate(int c)
    {
        _tlst.push_back(c);
        switch(_tstate)
        {
            case 0:
                if (c=='?') 
                    _tstate = 1;
                else if (c=='\\') 
                    _tstate = 4; 
                else
                    _tstate = -1;
                break;
            case 1:
                if (c=='?')
                    _tstate = 2;
                else
                    _tstate = -1;
                break;
            case 2:
                if (c=='=' || c=='/' || c=='^' || c=='(' || c==')' || c=='!' || c=='<' || c=='>' || c=='-')
                { 
                    _tlst.pop_back();
                    _tlst.pop_back();
                    _tlst.pop_back();
                    _tlst.push_back(trigraphMap(c));            
                    if (c =='/') {
                        _tstate = 4;
                    }
                    else {
                        _tstate = -1;
                    }
                }
                else if (c=='?')
                    _tstate = 2;
                else 
                    _tstate = -1;
                break;
            case 4:
                if (c=='u' || c=='U')
                    _tstate = 5;
                else if (c=='\n')
                {
                    _tlst.pop_back();
                    _tlst.pop_back();
                    _tstate = -1;
                }
                else
                    _tstate = -1;
                break;
            case 5: 
                if (isHex(c)) 
                {
                    _chex++;
                    _vhex = HexCharToValue(c);
                    _tstate = 6;
                }
                else
                    _tstate = -1;
                break;
            case 6:
                if (isHex(c))
                {
                    _chex++;
                    _vhex = (_vhex << 4) + HexCharToValue(c);
                    if (_chex == 4)
                    {
                        _tlst.pop_back();
                        _tlst.pop_back();
                        _tlst.pop_back();
                        _tlst.pop_back();
                        _tlst.pop_back();
                        _tlst.pop_back();
                        _tlst.push_back(_vhex); 
                    }
                    else if (_chex == 8) 
                    {
                        _tlst.pop_back();
                        _tlst.pop_back();
                        _tlst.pop_back();
                        _tlst.pop_back();
                        _tlst.pop_back();
                        _tlst.push_back(_vhex); 
                        _chex = 0;
                        _vhex = 0;
                        _tstate = -1;
                        break;
                    }
                    _tstate = 6;
                }
                else 
                    _tstate = -1;
                break;
            default:
                _tstate = -1;
                break;
        } 
        if (_tstate == -1) 
        {
            if (c=='?')
                _tstate = 1;
            else if (c=='\\')
                _tstate = 4;
            else 
            {
                _tstate = 0;
                _chex = 0;
                _vhex = 0;
            }
        }

        return _tstate;
    }

   
    bool            _rawMode; 
    vector<int>     _olst;
    unsigned int    _oidx;
    unsigned int    _tidx;


    //---------------------------------------
    // a double buffer implementation
    //
    int nextCode () 
    {
        if (_tidx < _tlst.size())
        {
            return _tlst[_tidx++];
        }
        else if (_oidx < _olst.size())
        {
            if (_rawStringMode)
            {
                return _olst[_oidx++];
            }
            else
            {
                _tlst.resize(0);
                while (translate( _olst[_oidx++] ) > 0) 
                {
                    if (_oidx >= _olst.size())
                    {
                        break;
                    }
                }
                
                if (_tlst.size() > 0)
                {
                    _tidx = 0;
                    return _tlst[_tidx++];
                }
                else
                {
                    cout << "TRANSLATE ERROR!" << endl;
                    return -1;
                }
            }
        } 
        else
        {
            return -1;
        }
    }


    int peek() 
    {
        if (_tidx < _tlst.size())
        {
            return _tlst[_tidx];
        }
        else if (_oidx < _olst.size())
        {
            if (_rawMode)
            {
                return _olst[_oidx];
            }
            else
            {
                _tlst.resize(0);
                while (translate( _olst[_oidx++] ) > 0) 
                {
                    if (_oidx >= _olst.size())
                    {
                        break;
                    }
                }
                
                if (_tlst.size() > 0)
                {
                    _tidx = 0;
                    return _tlst[_tidx];
                }
                else
                {
                    cout << "TRANSLATE ERROR!" << endl;
                    return -1;
                }
            }
        }
        else
        {
            return -1;
        }
    } 
   
    int     _lahead; 
    int     _idx;
    bool    _rawStringMode;


    void parse (vector<int>& inList)
    {
        _olst = inList;
        _oidx = 0;
        _tidx = 0;
        _rawStringMode = false;

        if (_olst.size() == 0)
        {
            output.emit_eof();
        }  
        else 
        {
            while (peek() != -1) 
            {
                if (isNonDigit(peek()))
                {
                    vector<int> id;
                    matchIdentifier(id);
                    if (compareCodeToStr(id, "uR") || compareCodeToStr(id,"u8R") || compareCodeToStr(id,"UR") || compareCodeToStr(id, "R"))
                    {
                        if (peek() == '"')
                        {
                            vector<int> rawStr;
                            vector<int> result;
                            matchRawStringLiteral(rawStr);
                            result.insert(result.end(), id.begin(), id.end());
                            result.insert(result.end(), rawStr.begin(), rawStr.end());
                            if (isNonDigit(peek()))
                            {
                                id.resize(0); 
                                matchIdentifier(id); 
                                result.insert(result.end(), id.begin(), id.end());
                                output.emit_user_defined_string_literal(UTF8Encoder::encode( result ));  
                            }
                            else
                            {
                                output.emit_string_literal(UTF8Encoder::encode( result ));  
                            }
                        } 
                        else
                        {
                            output.emit_identifier(UTF8Encoder::encode(id));
                        }
                    }
                    else if (compareCodeToStr(id, "u") || compareCodeToStr(id,"u8") || compareCodeToStr(id,"U"))
                    {
                        if (peek() == '"')
                        {
                            vector<int> str;
                            vector<int> result;
                            matchNonRawStringLiteral(str);
                            result.insert(result.end(), id.begin(), id.end());
                            result.insert(result.end(), str.begin(), str.end());
                            if (isNonDigit(peek()))
                            {
                                id.resize(0); 
                                matchIdentifier(id); 
                                result.insert(result.end(), id.begin(), id.end());
                                output.emit_user_defined_string_literal(UTF8Encoder::encode( result ));  
                            }
                            else
                            {
                                output.emit_string_literal(UTF8Encoder::encode( result ));  
                            }
                        }
                    }
                    else 
                    {
                        output.emit_identifier(UTF8Encoder::encode(id));
                    }
                } // end of identifier and string literal matching
                else if (peek() == '"')
                {
                    vector<int> str;
                    vector<int> result;
                    matchNonRawStringLiteral(str);
                    result.insert(result.end(), str.begin(), str.end());
                    if (isNonDigit(peek()))
                    {
                        vector<int> id;
                        matchIdentifier(id); 
                        result.insert(result.end(), id.begin(), id.end());
                        output.emit_user_defined_string_literal(UTF8Encoder::encode( result ));  
                    }
                    else
                    {
                        output.emit_string_literal(UTF8Encoder::encode( result ));  
                    }
                }
                else if (peek() == '\n')
                {
                    nextCode();
                    output.emit_new_line();
                }
            } // end of while
            output.emit_eof();
        }
    }


    bool compareCodeToStr(const vector<int>& code, const char* str)
    {
        if (code.size() == strlen(str))
        {
            for (unsigned int i=0 ; i< code.size(); i++)
            {
                if (code[i] != (int)str[i])
                {
                    return false;
                } 
            } 
            return true;
        }
        return false;
    }

    bool compareCodeToCode(const vector<int>& code1, const vector<int>& code2)
    {
        if (code1.size() == code2.size())
        {
            for (unsigned int i=0 ; i<code1.size() ; i++)
            {
                if (code1[i] != code2[i])
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    
    bool isNonDigit(int code)
    {
        if ( code >= 'a' && code <= 'z')
            return true;
        else if ( code >= 'A' && code <= 'Z')
            return true;
        else if ( code == '_')
            return true;
        else
            return false;
    }

    bool isDigit(int code)
    {
        if ( code >= '0' && code <= '9' )
        {
            return true;
        }
        return false;
    }
    
    bool isBasicChar(int code)
    {
        if (code>='a' && code<='z')
            return true;
        else if (code>='A' && code<='Z')
            return true;
        else if (code>='0' && code<='9')
            return true;
        else if (code=='_' || code=='{' || code=='}' || code=='[' || code==']' ||
                 code=='#' || code=='(' || code==')' || code=='<' || code=='>' ||
                 code=='%' || code==':' || code==';' || code=='.' || code=='?' ||
                 code=='*' || code=='+' || code=='-' || code=='/' || code=='^' ||
                 code=='&' || code=='|' || code=='~' || code=='!' || code=='=' ||
                 code==',' || code=='"' || code=='\''|| code==' ' ||
                 code=='\t' || code=='\v' || code=='\f'|| code=='\n')
            return true; 
        else
            return false;
    }
    
    bool isDchar(int code)
    {
        if (isBasicChar(code))
        {
            if (code!=' ' && code!='(' && code!=')' && code!='\\' && code!='\t' && code!='\v' && code!='\f' && code!='\n')
                return true;
            else
                return false;
        } 
        else
            return false;
    }

    
    bool matchPattern(vector<int>& pattern, vector<int>& result)
    {
        for (unsigned int i=0 ; i<pattern.size(); i++)
        {
            if (peek() == pattern[i])
                result.push_back(nextCode());
            else
                return false;
        }
        return true;
    }


    bool matchDchars(vector<int>& dchars)
    {
        while (isDchar(peek()))
        {
            dchars.push_back(nextCode());    
        }
        if (peek() == '(' || peek() == ')')
        {
            return true;
        }
        else {
            return false; 
        }
    }

    
    bool matchEscapeSequence(vector<int>& escape)
    {
        escape.push_back(nextCode());   // take '\\'
        int c1 = nextCode();
        if (c1=='\'' || c1=='"' || c1=='?' || c1=='\\' || c1=='a' || c1=='b' || c1=='f' || c1=='n' || c1=='r' || c1=='t' || c1=='v')
        {
            escape.push_back(c1);
            return true;
        }
        else if (c1=='x')
        {
            escape.push_back(c1);
            if (isHex(peek()))
            {
                escape.push_back(nextCode());     
                return true;
            }
            else
            {
                throw PPTokenizerException("Bad escape sequence");             
            }
        }
        else if (isHex(c1))
        {
            escape.push_back(c1);
            while (isHex(peek()))
            {
                escape.push_back(nextCode());
            }
            return true;
        }
        else if (isOctal(c1))
        {
            // another 1 or another 2 
            escape.push_back(c1);
            if (isOctal(peek()))
            {
                escape.push_back(nextCode());
                if (isOctal(peek()))
                {
                    escape.push_back(nextCode());
                }
            }
            return true;
        }
        else
        {
            throw PPTokenizerException("Bad escape sequence");             
        }
        return false;
    }

    bool matchSchars(vector<int>& schars)
    {
        while (peek() != -1)
        {
            if (peek() == '"' || peek()=='\n') 
            {
                break;
            }
            else if (peek() == '\\')
            {
                // UCN should be replaced in translate stage
                //
                vector<int> escape;
                if (matchEscapeSequence(escape))
                {
                    schars.insert(schars.end(), escape.begin(), escape.end());
                }
                else
                {
                    throw PPTokenizerException("Bad string literal");             
                }
            }
            else
            {
                schars.push_back(nextCode());
            }
            
        }       
        return true;
    }


    //--------------------------------------------------------------
    // Example : R"abc(xxxxxx)abc"
    // This function should return "xxxxxx" part and skip through
    // the last "abc" part
    //
    bool matchRchars(vector<int>& prefix, vector<int>& rchars)
    {
        vector<int> tmp;

        while (peek() != -1)
        {
            if (peek() == ')')
            {
                // match for the rest dchars
                nextCode();  // skip ) 
                vector<int> suffix;
                if (matchPattern(prefix, suffix) && peek()=='"')
                {
                    if (compareCodeToCode(prefix, suffix) == true)
                    {
                        nextCode();  // skip "
                        return true; 
                    }
                    else
                    {
                        rchars.push_back(')');
                        rchars.insert(rchars.end(), suffix.begin(), suffix.end());
                    }
                }
                else
                {
                    rchars.push_back(')');
                    rchars.insert(rchars.end(), suffix.begin(), suffix.end());
                }
            }
            else
            {
                rchars.push_back(nextCode());
            }
        }
        return false;
    }

    
    bool matchIdentifier(vector<int>& id)
    {
        if (isNonDigit(peek()))
        {
            id.push_back(nextCode()); 
            while ( isNonDigit(peek()) || isDigit(peek()) )
            {
                id.push_back(nextCode());
            }
            return true;
        }
        else
        {
            return false;
        }
    }


    bool matchRawStringLiteral(vector<int>& result)
    {
        vector<int> id;
        vector<int> dchars;
        vector<int> rchars;
        
        nextCode(); // skip "
        if (matchDchars(dchars) && peek() == '(') 
        {
            nextCode(); //skip (
            _rawStringMode = true;
            if (matchRchars(dchars, rchars))
            {
                // sucess
                result.insert(result.end(), id.begin(), id.end());
                result.push_back('"');
                result.insert(result.end(), dchars.begin(), dchars.end());
                result.push_back('(');
                result.insert(result.end(), rchars.begin(), rchars.end());
                result.push_back(')');
                result.insert(result.end(), dchars.begin(), dchars.end());
                result.push_back('"');
            }
            else
            {
                throw PPTokenizerException("Bad raw string literal");             
            }
            _rawStringMode = false;
            return true;
        }
        else
        {
            throw PPTokenizerException("Bad raw string literal");             
        }

        return false;
    }


    bool matchNonRawStringLiteral(vector<int>& result)
    {
        nextCode(); // skip "

        vector<int> schars;
        matchSchars(schars);
        if (peek()=='"')
        {
            //success
            nextCode(); // skip "
            result.push_back('"');
            result.insert(result.end(), schars.begin(), schars.end());
            result.push_back('"');
            return true;
        }
        else
        {
            throw PPTokenizerException("Bad string linteral");             
        }
        return false;
    }


    void process(int c)
    {
        if (c == EndOfFile)
        {
            output.emit_identifier("not_yet_implemented");
            output.emit_eof();
        }

        // TIP: Reference implementation is about 1000 lines of code.
        // It is a state machine with about 50 states, most of which
        // are simple transitions of the operators.
    }
};


int main()
{
    try
    {
        ostringstream oss;
        oss << cin.rdbuf();

        string input = oss.str();

        DebugPPTokenStream output;

        PPTokenizer tokenizer(output);
        
        vector<int> uncTokens;

        int code_unit;
        UTF8Decoder utf8Decoder(&input);
        while ((code_unit = utf8Decoder.nextCode()) > 0)
        {
            //tokenizer.process(code_unit);
            uncTokens.push_back(code_unit);
        }
        tokenizer.parse(uncTokens);

        // for (char c : input)
        // {
        //     unsigned char code_unit = c;
        //     tokenizer.process(code_unit);
        // }
        //tokenizer.process(EndOfFile);
    }
    catch (exception& e)
    {
        cerr << "ERROR: " << e.what() << endl;
        return EXIT_FAILURE;
    }
}


