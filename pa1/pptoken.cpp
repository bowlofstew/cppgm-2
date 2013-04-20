#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

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
            if (_rawMode)
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


    void parse (vector<int>& inList)
    {
        _olst = inList;
        _oidx = 0;
        _tidx = 0;
        _rawMode = false;

        if (_olst.size() == 0)
        {
            output.emit_eof();
        }  
        else 
        {
            _lahead = peek();
            if (_lahead is nondigit)
            {
                parseRawString();
            }

            //int c;
            //while ( (c = nextCode()) != -1 ) 
            //{
            //    cout << "Rich : " << (char)c << endl;
            //}
        }
    }


    bool parseStringLiteral()
    {
        vector<int> id;

        if (matchIdentifier(id))          
        {
            if ( id is "uR" "u8R" "UR" "LR" "R")
            {
                if ( peek is "\"" )
                {
                    _rawStringMode = true;
                    if (parseRcharSequence()) 
                    {
                    }
                    else
                    {
                        return false;
                    }
                    //vector<int> prefix;
                    //while ( peek() is d-char-seq )
                    //{
                    //    prefix.push_back(nextCode());
                    //}
                    //if (peek() == '(')
                    //{
                    //    nextCode();  // '('
                    //    
                    //    while (peek() is r-char) 
                    //    {
                    //        
                    //    }
                    //    
                    //    vector<int> suffix;
                    //    for (unsigned i=0 ; i<prefix.size() ; i++)
                    //    {
                    //        if (peek() == prefix[i])
                    //        {
                    //            suffix.push_back(nextCode()); 
                    //        }
                    //        else
                    //        {
                    //            break;
                    //        }
                    //    } 

                    //    if (prefix equals suffix) 
                    //    {
                    //        if (peek == '\"')
                    //        {
                    //            // raw string ok! 
                    //        }
                    //        else
                    //        {
                    //           // no matching end quote 
                    //        }
                    //    }
                    //}
                }           
                else
                {
                    emit id
                }
            }
            else if (id is "u" "u8" "U" "L" )
            {
                if (peek is "\"")
                {
                    parseScharSequence(); 
                }
            }
            else
            {
                emit id
                return true;
            }
        }
        else if (peek is "\"")
        {
            return parseScharSequence(); 
        }
        else
        {
            // does not start with a \" or u U L
            return false;
        }
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












