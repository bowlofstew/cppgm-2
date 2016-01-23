#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <exception>

using namespace std;

class Hex2binaryException : public std::exception
{
  public:
    Hex2binaryException(const char* msg)
        : _errMsg(msg)
    {
    }

    virtual ~Hex2binaryException() throw()
    {
    }

    virtual const char* what() const throw()
    {
        return _errMsg.c_str();
    }

  private:
    std::string _errMsg;
 
};

string to_bit( unsigned char a ) 
{
    stringstream ss;
    for (int i=0; i<8*sizeof(char); i++)
    {
       if ( a & ( 0x1 << i) ) {
           ss << "1";
       }
       else {
           ss << "0";
       }
    }
    string s = ss.str();
    return string(s.rbegin(), s.rend());
}


string to_hex( unsigned char in ) 
{
    static char hexmap[] = {'0','1','2','3','4','5','6','7','8','9','A', 'B', 'C','D', 'E', 'F'};

    stringstream ss;
    unsigned int a = in;
    unsigned leftHalf = a >> 4;
    unsigned rightHalf = a & 0x0F;
    ss << hexmap[leftHalf] << hexmap[rightHalf];
    return ss.str();
}


string to_int (unsigned char a) {
    unsigned i = a;
    stringstream ss;
    ss << i;
    return ss.str();
}


class Hex2binary {
  public:

    string _input;
    char*  _hex2numMap;
    unsigned myTotalBytes;;
    unsigned myLineBytes;
    unsigned myContentBytes;;
    unsigned myCharIdx;
    unsigned myLineIdx;
    unsigned myPrevLineNum;
    vector<unsigned char> myData;


    Hex2binary ( const string& inFile) 
    {
        build_hex2num();

        ifstream infs (inFile.c_str(), ios::in);
        stringstream buffer;
        buffer << infs.rdbuf();
        _input = buffer.str();
        infs.close();

        myTotalBytes=0;
        myLineBytes=0;
        myContentBytes=0;
        myCharIdx = 0;
        myLineIdx = 0;
        myPrevLineNum = 0;
    }

    ~Hex2binary () {
        delete [] _hex2numMap;
    }

    void build_hex2num()
    {
        _hex2numMap = new char[256];
        _hex2numMap['0'] = 0;
        _hex2numMap['1'] = 1;
        _hex2numMap['2'] = 2;
        _hex2numMap['3'] = 3;
        _hex2numMap['4'] = 4;
        _hex2numMap['5'] = 5;
        _hex2numMap['6'] = 6;
        _hex2numMap['7'] = 7;
        _hex2numMap['8'] = 8;
        _hex2numMap['9'] = 9;
        _hex2numMap['a'] = 10;
        _hex2numMap['b'] = 11;
        _hex2numMap['c'] = 12;
        _hex2numMap['d'] = 13;
        _hex2numMap['e'] = 14;
        _hex2numMap['f'] = 15;
    }

    unsigned char hex_to_char( char left, char right) 
    {
        unsigned char cleft = _hex2numMap[left];
        unsigned char cright = _hex2numMap[right];

        unsigned char ret = (cleft << 4) | cright;
        return ret;
    }

    unsigned int hex_to_int (string hexStr)
    {
        unsigned int ret = 0;
        for (int i=0; i<hexStr.size(); i++)
        {
            if (i==0)
                ret = _hex2numMap[ hexStr[i] ];
            else
                ret = (ret << 4) + _hex2numMap[ hexStr[i] ];
        }
        return ret;
    }

    void skip_space( ) {
        while ( myCharIdx < _input.size() )
        {
            if (_input[myCharIdx] == ' ' )  {
                myCharIdx++;
                continue;
            } else {
                break;
            }
        }
    }

    void skip_space_and_lineend ( ) {
        while ( myCharIdx < _input.size() )
        {
            if (_input[myCharIdx] == ' ' || _input[myCharIdx] == '\n' )  {
                myCharIdx++;
                continue;
            } else {
                break;
            }
        }
    }


    void match_space() {
        if (_input[myCharIdx] == ' ') {
            skip_space();
        }
        else {
            stringstream ss;
            ss << "ERROR, exepct to match space char at line " << myLineIdx ;
            throw Hex2binaryException( ss.str().c_str() );
        }
    }

    char match_lineend() {
        if (_input[myCharIdx] == '\n') {
            myCharIdx++;
            return ' ';
        }
        else {
            stringstream ss;
            ss << "ERROR, exepct to match line end char at line " << myLineIdx ;
            throw Hex2binaryException( ss.str().c_str() );
        }
    }

    bool isHexCode( char a ) {
        if (( a >= '0' && a<='9') || (a >='a' && a <='f')) {
            return true;
        }
        return false;
    }

    char match_hexChar() {
        char a = _input[myCharIdx];

        if ( isHexCode(a) ) {
            myCharIdx++;
            return a;
        }
        else {
            stringstream ss;
            ss << "ERROR, exepct to match hex char at line " << myLineIdx ;
            throw Hex2binaryException( ss.str().c_str() );
        }
    }

    char peek() {
        return _input[myCharIdx];
    }

    void parse_hex_file_header () {

        int headerBytes = 0;

        //--- pattern string
        skip_space_and_lineend();
        stringstream ss0;
        for (int i=0; i<16; i++) {
            unsigned char a = match_hexChar();
            ss0 << a;
        }
        skip_space();
        match_lineend();

        //--- total bytes
        skip_space_and_lineend();
        stringstream ss;
        for (int i=0; i<8; i++) {
            unsigned char a = match_hexChar();
            ss << a;
        }
        myTotalBytes = hex_to_int( ss.str() );
        match_space();

        stringstream ss1;
        for (int i=0; i<8; i++) {
            unsigned char a = match_hexChar();
            ss1 << a;
        }
        myLineBytes = hex_to_int( ss1.str() );
        match_space();

        stringstream ss2;
        for (int i=0; i<8; i++) {
            unsigned char a = match_hexChar();
            ss2 << a;
        }
        myContentBytes = hex_to_int( ss2.str() );
        match_lineend();

        cout << "Pattern: " << ss0.str() << endl;
        cout << "TotalBytes: " << myTotalBytes << endl;
        cout << "LineNumBytes: " << myLineBytes << endl; 
        cout << "ContentBytes: " << myContentBytes << endl;


        // while (headerBytes <20) {
        //     if (headerBytes == 0) {
        //         skip_space();
        //         string dbString = _input.substr(myCharIdx,16);
        //         myCharIdx+=16;
        //         headerBytes = 8;
        //         cout << dbString << endl;
        //     } else if (headerBytes == 8) {
        //         skip_space();
        //         myTotalBytes = hex_to_int(_input.substr(myCharIdx,8));
        //         myCharIdx+=8;
        //         headerBytes += 4;
        //         cout << "Total bytes: " << myTotalBytes << endl;
        //     } else if (headerBytes == 12 ) {
        //         skip_space();
        //         myLineBytes = hex_to_int(_input.substr(myCharIdx,8));
        //         myCharIdx+=8;
        //         headerBytes += 4;
        //         cout << "lineNumBytes: " << myLineBytes << endl;
        //     } else if (headerBytes == 16 ) {
        //         skip_space();
        //         myContentBytes = hex_to_int(_input.substr(myCharIdx,8));
        //         myCharIdx+=8;
        //         headerBytes += 4;
        //         cout << "contentNumBytes: " << myContentBytes << endl;
        //     }
        //     else {
        //         cout << "Error!!" << endl;
        //     }
        // }
    }

    void parse_hex_file_line () {
        int lineHexNum = myLineBytes * 2; 
        int contentHexNum = myContentBytes * 2;
        unsigned int localCheckSum = 0;

        skip_space_and_lineend();

        if (myCharIdx == _input.size()) {
            return;
        }

        stringstream liness;
        for (int i=0; i<lineHexNum; i++) {
            char a = match_hexChar();
            liness << a;
        }

        match_space();

        stringstream contentss;


        // for (int i=0; i<contentHexNum; i++) {
        while ( isHexCode( peek() ) ) {
            unsigned char a = match_hexChar();
            localCheckSum += _hex2numMap[a];
            contentss << a;
        }
        localCheckSum = localCheckSum % 256;

        match_space();
      
        stringstream ckss;
        char c1 = match_hexChar();
        char c2 = match_hexChar();
        ckss << c1 << c2;
        unsigned int checkSum = hex_to_int( ckss.str() );

        match_lineend();

        unsigned int lineNum  = hex_to_int( liness.str() );

        if (lineNum != myPrevLineNum+1) {
            throw Hex2binaryException( "Error, discontinuous line number!" );
        }

        if (localCheckSum != checkSum) {
            throw Hex2binaryException( "Error, inconsistent checksum!" );
        }

        string tmp = contentss.str();
        myData.insert( myData.end(), tmp.begin(), tmp.end() );
        myPrevLineNum = lineNum;



        // skip_space();
        // string lineNumStr = _input.substr(myCharIdx, lineHexNum);
        // myCharIdx += lineHexNum;

        // skip_space();
        // while ( myCharIdx < _input.size()) {
        //     if (_input[myCharIdx] == '\n') {
        //         break;
        //     }
        //     else if (_input[myCharIdx] == ' ') {
        //         myCharIdx++;
        //         continue;
        //     }
        //     else {
        //         myData.push_back( _input[myCharIdx]);
        //         myCharIdx++;
        //     }
        // }
    }

    void parse_hex_file () {
        parse_hex_file_header( );
        while ( myCharIdx < _input.size() ) {
            parse_hex_file_line( );
        }
    }


    void dump_binary_file( string outfname )
    {
        ofstream ofs( outfname.c_str(), ios::out|ios::binary );
        char buffer [1024];
        int bidx = 0;

        parse_hex_file();

        int i=0;
        while( i<myData.size() ) {
            unsigned char t =  hex_to_char ( myData[i], myData[i+1] );                
            
            buffer[bidx++] = t;
            if (bidx == 1024) {
                ofs.write( buffer, bidx);
                bidx = 0;
            }
            i+=2;
        }
        if (bidx > 0) {
            ofs.write( buffer, bidx);
            bidx = 0;
        }

        ofs.close();
    }
};


class Binary2hex {
  public:

    vector<char> _buffer;
    char* _hex2numMap;

    Binary2hex ( const string& inFile) 
    {
        build_hex2num();
        ifstream input( inFile.c_str() , ios::in|ios::binary|ios::ate );
        if (input.is_open()) 
        {
            unsigned size = input.tellg();
            char *mem = new char[size];
            input.seekg(0, ios::beg);
            input.read(mem,size);
            input.close();
            _buffer.insert( _buffer.begin(), mem, mem+size);
        }
    }

    void build_hex2num()
    {
        _hex2numMap = new char[256];
        _hex2numMap['0'] = 0;
        _hex2numMap['1'] = 1;
        _hex2numMap['2'] = 2;
        _hex2numMap['3'] = 3;
        _hex2numMap['4'] = 4;
        _hex2numMap['5'] = 5;
        _hex2numMap['6'] = 6;
        _hex2numMap['7'] = 7;
        _hex2numMap['8'] = 8;
        _hex2numMap['9'] = 9;
        _hex2numMap['a'] = 10;
        _hex2numMap['b'] = 11;
        _hex2numMap['c'] = 12;
        _hex2numMap['d'] = 13;
        _hex2numMap['e'] = 14;
        _hex2numMap['f'] = 15;
    }


    string char_to_hex( unsigned char in ) 
    {
        static char hexmap[] = {'0','1','2','3','4','5','6','7','8','9','a', 'b', 'c','d', 'e', 'f'};
    
        stringstream ss;
        unsigned int a = in;
        unsigned leftHalf = a >> 4;
        unsigned rightHalf = a & 0x0F;
        ss << hexmap[leftHalf] << hexmap[rightHalf];
        return ss.str();
    }

    string int_to_hex ( unsigned int in )
    {
        stringstream ss;

        int size = sizeof(unsigned int);

        for (int i=0; i<size; i++) {
            unsigned char a = (in >> ((size * 8) - (8 * (i+1)))) & 0xFF; 
            ss << char_to_hex(a);
        }

        return ss.str();
    }

    void dump_hex_file( string outfname , unsigned lineNumBytes, unsigned contentBytes)
    {
        ofstream ofs( outfname.c_str(), ios::out|ios::binary );
        cout << "File size : " << _buffer.size() << endl;

        // dump header
        ofs << " 0123456789abcdef" << endl;
        ofs << " " << int_to_hex(_buffer.size()) << " " << 
                      int_to_hex( lineNumBytes ) << " "  << 
                      int_to_hex( contentBytes ) << endl;
       
        unsigned int lineNum = 1;
        unsigned int checkSum = 0;
        for (unsigned i=0; i<_buffer.size(); i++)
        {
            if ( i % contentBytes  == 0) {
                ofs << endl << " " ; 
                string lineStr = int_to_hex(lineNum);
                ofs << lineStr.substr( lineStr.size() - lineNumBytes*2 )  << " ";
                lineNum++;
            }
            unsigned char a = _buffer[i];
            string code = char_to_hex( a ) ; 
            ofs << code;
            checkSum = checkSum + _hex2numMap[code[0]] + _hex2numMap[code[1]];

            if (i % contentBytes == (contentBytes - 1) || i == _buffer.size()-1) {
                unsigned char b = checkSum % 256;
                ofs << " " << char_to_hex( b ) ; 
                checkSum = 0;
            }
        }
        ofs << endl;

        for (int j=0; j<100; j++) {
            ofs << endl;
        }
        ofs.close();
    }
};

void helpMsg()
{
    cout << "dump_hex [-h2b] [-line <n>] [-content <n>] <inf> -out <outf>" << endl;
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        helpMsg();
        return -1;
    } 

    string mode = "b2h";
    string inFileName = "";
    string outFileName = "out.hex";
    int    lineNumBytes = 3;
    int    contentBytes = 48;

    vector<string> args( argv, argv + argc );

    for (int i=1; i<args.size() ; i++) {
        if (args[i] == "-h2b") {
            mode = "h2b";
        } else if ( args[i] == "-out" ) {
            outFileName = args[i+1];
            i++;
        } else {
            inFileName = args[i];
        }
    }

    if (mode == "b2h") {
        Binary2hex b2h( inFileName );
        b2h.dump_hex_file( outFileName , lineNumBytes, contentBytes);
    }
    else {
        outFileName = "out.bin";
        Hex2binary h2b ( inFileName );
        h2b.dump_binary_file( outFileName );
    }

    return 0;
}





