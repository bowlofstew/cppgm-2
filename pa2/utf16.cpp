#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <exception>
#include <vector>


class UTF16DecoderException : public std::exception 
{
public:
    UTF16DecoderException (const char* msg)
        : _errMsg(msg)
    {
    }
    
    virtual const char * what () const throw()
    {
        return _errMsg.c_str();
    }
    
    virtual ~UTF16DecoderException () throw()
    {
    }
private:
    std::string   _errMsg;
};



class UTF16Decoder 
{
public:
    UTF16Decoder (const char* fname) 
    {
        _is.open(fname, std::ifstream::binary);             
        _is.seekg (0, _is.end);
        _fileSize = _is.tellg();
        _is.seekg (0, _is.beg);
        _fileIdx = 0;

        _byteBuf = new char [BUFSIZE];
        _byteBufIdx = 0;
        _byteBufSize = 0;

        _sptr = NULL;
        _sidx = 0;
    }

    UTF16Decoder (std::string* s)
        : _sidx(0), _sptr(s)
    {
    } 

    ~UTF16Decoder ()
    {
        if (_sptr == NULL)
        {
            _is.close();
            delete [] _byteBuf;
        }
    }

    int nextCode () {
        unsigned char b;  
        int code=0;
        if (nextByte(b)) 
        {
            int rest = 0; 
            if ((b>>7) == 0) 
            {
                return (b & 0x7f);  
            }  
            else if ((b>>5) == 6)  // 110
            {
                code = b & 0x1f; 
                rest = 1;
            }
            else if ((b>>4) == 14)  // 1110
            {
                code = b & 0x0f;
                rest = 2;
            } 
            else if ((b>>3) == 30)  // 11110
            {
                code = b & 0x07;
                rest = 3;
            }
            else 
            {
                reportError("Error: bad UTF8 format");
            }
           
            for (int i=0; i<rest; i++) {
                if (nextByte(b)) 
                {
                    if ((b>>6) == 2) // 10
                    {
                        code = (code<<6) + (b & 0x3f);
                    }
                    else 
                    {
                        reportError("Error: bad UTF8 format");
                    }
                } 
                else 
                {
                    reportError("Error: bad UTF8 format");
                }
            } 
        } 
        else 
        {
            return -1;
        }
        return code;
    }

    bool nextByte (unsigned char& b) 
    {
        if (_sptr != 0) 
        {
            if (_sidx < _sptr->size()) 
            {
                b = (*_sptr)[_sidx];
                _sidx++; 
                return true;
            } 
            else
            {
                return false;
            }
        }
        else if (_byteBufIdx == _byteBufSize) 
        {
            // read another block 
            if (_fileSize >= BUFSIZE) 
            {
                _is.read (_byteBuf, BUFSIZE);             
                _byteBufSize = BUFSIZE;
                _fileSize -= BUFSIZE;
            }
            else if (_fileSize > 0) 
            {
                _is.read (_byteBuf, _fileSize);
                _byteBufSize = _fileSize;
                _fileSize = 0;
            } 
            else 
            {
                return false;
            }
            _byteBufIdx = 0;
        }
        b = _byteBuf[_byteBufIdx++];
        return true;
    }

    void reportError (const char* msg) 
    {
        if (_sptr == NULL)
        {
            delete [] _byteBuf; 
            _is.close();
        }
        throw UTF16DecoderException(msg);
    }

private:
    // static const enum and int can be defined directly in the class
    //
    static const int BUFSIZE = 256;

    char*               _byteBuf;
    int                 _byteBufIdx;
    int                 _byteBufSize;
    int                 _fileSize;
    int                 _fileIdx;
    std::ifstream       _is;
    unsigned int        _sidx;
    std::string*        _sptr;
};


class UTF16Encoder
{
public:
    
    static std::vector<short> encode(std::vector<int>& code)
    {
        std::vector<short> out;
        for (unsigned int i=0 ; i<code.size() ; i++)
        {
            unsigned short w1, w2;
            if ( encode( code[i], w1, w2 ) )
            {
                out.push_back( w1 );
                out.push_back( w2 );
            }
            else 
            {
                out.push_back( w1 );
            }
        }
        return out;
    }

    static bool encode(int code, unsigned short& w1, unsigned short& w2)
    {
        if (code < 0x10000)
        {
            w1 = code;
            return false;
        }
        else
        {
            int u = code - 0x10000;
            w1 = (13 << 12) + (8 << 8);
            w2 = (13 << 12) + (12 << 8);
            int u_h = (u & 0x3FC00) >> 10;
            int u_l = u & 0x3FF;
            w1 = w1 | u_h; 
            w2 = w2 | u_l;
            return true;
        }
    }
};


#ifdef utf16
int main(void) {
    using namespace std;

    ofstream of("test.txt"); 
    char tdata [] = {0x24, 0xc2, 0xa2, 0xe2, 0x82, 0xac, 0xf0, 0xa4, 0xad, 0xa2}; 
    of.write(tdata, sizeof(tdata));
    of.close();
    
    UTF8Decoder bf("test.txt");         
    int code;
    while ((code = bf.nextCode()) != -1) 
    {
        cout << code << endl;
        
        vector<char> utfdata;
        UTF8Encoder::encode(code, utfdata);
        for (vector<char>::iterator it=utfdata.begin(); it != utfdata.end() ; ++it) 
        {
            int uc = (unsigned char) *it;
            cout << hex << uc << ",";  
        }
        cout << endl << dec;
        
    }    

    return 0;
}
#endif




