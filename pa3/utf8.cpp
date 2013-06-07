#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <exception>
#include <vector>


class UTF8DecoderException : public std::exception 
{
public:
    UTF8DecoderException (const char* msg)
        : _errMsg(msg)
    {
    }
    
    virtual const char * what () const throw()
    {
        return _errMsg.c_str();
    }
    
    virtual ~UTF8DecoderException () throw()
    {
    }
private:
    std::string   _errMsg;
};



class UTF8Decoder 
{
public:
    UTF8Decoder (const char* fname) 
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

    UTF8Decoder (std::string* s)
        : _sidx(0), _sptr(s)
    {
    } 

    ~UTF8Decoder ()
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
        throw UTF8DecoderException(msg);
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


class UTF8Encoder
{
public:
    
    static std::string encode(std::vector<int>& code)
    {
        std::string s; 
        for (unsigned int i=0 ; i<code.size() ; i++)
        {
            encode(code[i], s);
        }
        return s;
    }

    static bool encode(int code, std::string& out)
    {
        if (code < 0x80)
        {
            out.push_back((char) code);
        }
        else if (code < 0x7ff)
        {
            char hiByte = 0xC0 | (code >> 6);
            char loByte = 0x80 | (code & 0x3f);
            out.push_back(hiByte);
            out.push_back(loByte);
        }
        //else if (code < 0xdfff)
        //{
        //    return false;
        //}
        else if (code < 0xffff)
        {
            char b1 = 0xe0 | (code >> 12);
            char b2 = 0x80 | ((code & 0x0fc0) >> 6);
            char b3 = 0x80 | (code & 0x3f); 
            out.push_back(b1); 
            out.push_back(b2);
            out.push_back(b3);
        } 
        else if (code < 0x10ffff)
        {
            char b1 = 0xf0 | (code >> 18);
            char b2 = 0x80 | ((code >> 12) & 0x3f);
            char b3 = 0x80 | ((code >> 6) & 0x3f);
            char b4 = 0x80 | (code & 0x3f);
            out.push_back(b1); 
            out.push_back(b2);
            out.push_back(b3);
            out.push_back(b4);
        }
        else
        {
            return false;
        }
        return true;
    }
};


#ifdef utf8
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
        
        std::vector<char> utfdata;
        UTF8Encoder::encode(code, utfdata);
        for (std::vector<char>::iterator it=utfdata.begin(); it != utfdata.end() ; ++it) 
        {
            int uc = (unsigned char) *it;
            cout << hex << uc << ",";  
        }
        cout << endl << dec;
        
    }    

    return 0;
}
#endif




