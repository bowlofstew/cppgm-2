// (C) 2013 CPPGM Foundation www.cppgm.org.  All rights reserved.

#ifndef PA3
#pragma once
#endif

#include <string>
#include "utf8.cpp"
#include "utf16.cpp"
#include "pptoken.cpp"
#include "posttoken.cpp"

using namespace std;

// mock implementation of IsDefinedIdentifier for PA3
// return true iff first code point is odd
bool PA3Mock_IsDefinedIdentifier(const string& identifier)
{
	if (identifier.empty())
		return false;
	else
		return identifier[0] % 2;
}



class PPCtrlExprEvalException : public exception
{
  public:
    PPCtrlExprEvalException(const char* errMsg) 
        : _errMsg(errMsg)
    {
    }
    virtual ~PPCtrlExprEvalException() throw() {}

    virtual const char* what() const throw() 
    {
        return _errMsg.c_str();
    }

  private:
    string _errMsg;
};



class PPCtrlExprResult
{
  public:
    PPCtrlExprResult(unsigned long v=0, bool isNegative=false, bool isUnsigned=false, bool isErr=false) 
        : _value(v), _isNegative(isNegative), _isUnsigned(isUnsigned), _isErr(isErr)  
    {
        if (_isUnsigned && _isNegative)
        {
            long t = _value * -1; 
            _value = t;
            _isNegative = false;
        }
    }

    PPCtrlExprResult(const PPCtrlExprResult &a)
    {
        _value = a._value;
        _isNegative = a._isNegative;
        _isUnsigned = a._isUnsigned;
        _isErr = a._isErr;
    }

    ~PPCtrlExprResult() 
    {
    }

    void promote()
    {
        _isUnsigned = true; 

        long t;
        if (_isNegative)
            t = _value * -1;
        else
            t = _value;
        
        _value = t;
        _isNegative = false;
    }

    PPCtrlExprResult operator+(const PPCtrlExprResult& a)
    {
        unsigned long tv;
        bool tNegative;
        bool tUnsigned = _isUnsigned || a._isUnsigned;
        bool tErr = _isErr || a._isErr;


        if (_isNegative == false && a._isNegative == false)
        {
            tv = _value + a._value;         
            tNegative = false;
        }
        else if (_isNegative == false && a._isNegative == true)
        {
            tv = (_value > a._value) ? _value - a._value : a._value - _value;        
            tNegative = _value < a._value ? true : false;
        }
        else if (_isNegative == true && a._isNegative == false)
        {
            tv = (_value > a._value) ? _value - a._value : a._value - _value;
            tNegative = _value < a._value ? false: true;
        }
        else //if (_isNegative == true && a._isNegative == true)
        {
            tv = _value + a._value;         
            tNegative = true;
        }

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }


    PPCtrlExprResult operator-(const PPCtrlExprResult& a)
    {
        unsigned long tv;
        bool tNegative;
        bool tUnsigned = _isUnsigned || a._isUnsigned;
        bool tErr = _isErr || a._isErr;

        tUnsigned = _isUnsigned || a._isUnsigned;
        if (_isNegative == false && a._isNegative == false)
        {
            tv = (_value > a._value) ? _value - a._value : a._value - _value;         
            tNegative = (_value > a._value) ? false : true;
        }
        else if (_isNegative == false && a._isNegative == true)
        {
            tv = _value + a._value;
            tNegative = false;
        }
        else if (_isNegative == true && a._isNegative == false)
        {
            tv = _value + a._value;
            tNegative = true;
        }
        else //if (_isNegative == true && a._isNegative == true)
        {
            tv = (_value > a._value) ? _value - a._value : a._value - _value;         
            tNegative = (_value > a._value) ? true : false; 
        }

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }

    PPCtrlExprResult operator*(PPCtrlExprResult a)
    {
        unsigned long tv;
        bool tUnsigned;
        bool tNegative;
        bool tErr;

        if (_isUnsigned || a.isUnsigned())
        {
            this->promote();
            a.promote();
        }

        tUnsigned = _isUnsigned || a._isUnsigned;
        tNegative = _isNegative ^ a._isNegative;
        tErr = _isErr || a._isErr;
        tv = _value * a._value;

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }

    PPCtrlExprResult operator/(PPCtrlExprResult a)
    {
        unsigned long tv;
        bool tUnsigned;
        bool tNegative;
        bool tErr;

        tUnsigned = _isUnsigned || a._isUnsigned;
        tNegative = _isNegative ^ a._isNegative;
        tErr = _isErr || a._isErr;

        if (_isUnsigned || a.isUnsigned())
        {
            this->promote();
            a.promote();
        }

        if (a._value != 0)
        {
            tv = _value / a._value;
            tErr = tErr || false;
        }
        else
        {
            tErr = true;
            tv = 0;
        }
        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }


    PPCtrlExprResult operator%(const PPCtrlExprResult& a)
    {
        unsigned long tv;
        bool tUnsigned;
        bool tNegative;
        bool tErr;

        tUnsigned = _isUnsigned; 
        tNegative = _isNegative;
        tErr = _isErr || a._isErr;

        if (a._value != 0)
        {
            tv = _value % a._value;
            tErr = tErr || false;
        }
        else
        {
            tErr = true;
            tv = 0;
        }
        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }

    PPCtrlExprResult operator>>(const PPCtrlExprResult& a)
    {
        unsigned long tv;
        bool tUnsigned;
        bool tNegative;
        bool tErr;

        tUnsigned = _isUnsigned;
        tNegative = _isNegative;
        tErr = _isErr || a._isErr;

        if ((a._isNegative && a._value !=0) || a._value >= 64)
        {
            tErr = true;
            tv = 0;
        }
        else
        {
            if (_isNegative)
            {
                long stv = _value * -1;
                tv = (stv >> a._value) * -1;
            }
            else
            {
                tv = _value >> a._value;
            }
        }
        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }

    PPCtrlExprResult operator<<(const PPCtrlExprResult& a)
    {
        unsigned long tv;
        bool tUnsigned;
        bool tNegative;
        bool tErr;

        tUnsigned = _isUnsigned;
        tNegative = _isNegative;
        tErr = _isErr || a._isErr;

        if ((a._isNegative && a._value!=0) || a._value >= 64)
        {
            tErr = true;
            tv = 0;
        }
        else
        {
            tv = _value << a._value;
        }
        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }


    PPCtrlExprResult operator>(PPCtrlExprResult a)
    {
        unsigned long tv;
        bool tUnsigned = false;
        bool tNegative = false;
        bool tErr = _isErr || a._isErr;

        if (_isUnsigned || a.isUnsigned())
        {
            this->promote();
            a.promote();
        }


        if (_isNegative == false && a._isNegative == false)
        {
            tv = (_value > a._value) ? 1 : 0;
        }
        else if (_isNegative == false && a._isNegative == true)
        {
            if (_value==0 && a._value==0)
                tv = 0;
            else
                tv = 1; 
        }
        else if (_isNegative == true && a._isNegative == false)
        {
            tv = 0;
        }
        else //if (_isNegative == true && a._isNegative == true)
        {
            tv = (_value < a._value) ? 1 : 0;
        }

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }

    PPCtrlExprResult operator>=(PPCtrlExprResult a)
    {
        unsigned long tv;
        bool tUnsigned = false;
        bool tNegative = false;
        bool tErr = _isErr || a._isErr;

        if (_isUnsigned || a.isUnsigned())
        {
            this->promote();
            a.promote();
        }

        if (_isNegative == false && a._isNegative == false)
        {
            tv = (_value >= a._value) ? 1 : 0;
        }
        else if (_isNegative == false && a._isNegative == true)
        {
            tv = 1; 
        }
        else if (_isNegative == true && a._isNegative == false)
        {
            if (_value==0 && a._value==0)
                tv = 1;
            else 
                tv = 0;
        }
        else //if (_isNegative == true && a._isNegative == true)
        {
            tv = (_value <= a._value) ? 1 : 0;
        }

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }

    PPCtrlExprResult operator<(PPCtrlExprResult a)
    {
        unsigned long tv;
        bool tUnsigned = false;
        bool tNegative = false;
        bool tErr = _isErr || a._isErr;

        if (_isUnsigned || a.isUnsigned())
        {
            this->promote();
            a.promote();
        }

        if (_isNegative == false && a._isNegative == false)
        {
            tv = (_value < a._value) ? 1 : 0;
        }
        else if (_isNegative == false && a._isNegative == true)
        {
            tv = 0;
        }
        else if (_isNegative == true && a._isNegative == false)
        {
            if (_value==0 && a._value==0)
                tv = 0;
            else
                tv = 1;
        }
        else //if (_isNegative == true && a._isNegative == true)
        {
            tv = (_value > a._value) ? 1 : 0;
        }

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }

    PPCtrlExprResult operator<=(PPCtrlExprResult a)
    {
        unsigned long tv;
        bool tUnsigned = false;
        bool tNegative = false;
        bool tErr = _isErr || a._isErr;

        if (_isUnsigned || a.isUnsigned())
        {
            this->promote();
            a.promote();
        }

        if (_isNegative == false && a._isNegative == false)
        {
            tv = (_value <= a._value) ? 1 : 0;
        }
        else if (_isNegative == false && a._isNegative == true)
        {
            if (_value==0 && a._value==0)
                tv = 1;
            else
                tv = 0; 
        }
        else if (_isNegative == true && a._isNegative == false)
        {
            tv = 1;
        }
        else //if (_isNegative == true && a._isNegative == true)
        {
            tv = (_value >= a._value) ? 1 : 0;
        }

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }


    PPCtrlExprResult operator!=(PPCtrlExprResult a)
    {
        unsigned long tv;
        bool tUnsigned = false;
        bool tNegative = false;
        bool tErr = _isErr || a._isErr;

        if (_isUnsigned || a.isUnsigned())
        {
            this->promote();
            a.promote();
        }

        if (_value==0 && a._value==0)
        {
            tv = 0;
        }
        else
        {
            if (_isNegative == false && a._isNegative == false)
            {
                tv = (_value != a._value);
            }
            else if (_isNegative == false && a._isNegative == true)
            {
                tv = 1; 
            }
            else if (_isNegative == true && a._isNegative == false)
            {
                tv = 1;
            }
            else //if (_isNegative == true && a._isNegative == true)
            {
                tv = (_value != a._value);
            }
        }

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }


    PPCtrlExprResult operator==(PPCtrlExprResult a)
    {
        unsigned long tv;
        bool tUnsigned = false;
        bool tNegative = false;
        bool tErr = _isErr || a._isErr;
        if (_isUnsigned || a.isUnsigned())
        {
            this->promote();
            a.promote();
        }

        if (_value==0 && a._value==0)
        {
            tv = 1;
        }
        else
        {
            if (_isNegative == false && a._isNegative == false)
            {
                tv = (_value == a._value);
            }
            else if (_isNegative == false && a._isNegative == true)
            {
                tv = 0;
            }
            else if (_isNegative == true && a._isNegative == false)
            {
                tv = 0;
            }
            else //if (_isNegative == true && a._isNegative == true)
            {
                tv = (_value == a._value);
            }
        }

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }


    PPCtrlExprResult operator&(PPCtrlExprResult a)
    {
        if (_isUnsigned || a.isUnsigned())
        {
            promote();
            a.promote();
        } 
        unsigned long tv;
        bool tUnsigned = _isUnsigned || a._isUnsigned;
        bool tNegative = _isNegative && a._isNegative;
        bool tErr = _isErr || a._isErr;

        if (_isNegative == false && a._isNegative == false)
        {
            tv = (_value & a._value);
        }
        else if (_isNegative == false && a._isNegative == true)
        {
            long t2 = a._value * -1;
            tv = _value & t2;
        }
        else if (_isNegative == true && a._isNegative == false)
        {
            long t1 = _value * -1;
            tv = t1 & a._value;
        }
        else //if (_isNegative == true && a._isNegative == true)
        {
            long t1 = _value * -1;
            long t2 = a._value * -1;
            long t = (t1 & t2); 
            tv = t * -1;
        }

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }


    PPCtrlExprResult operator|(PPCtrlExprResult a)
    {
        if (_isUnsigned || a.isUnsigned())
        {
            promote();
            a.promote();
        } 
 
        unsigned long tv;
        bool tUnsigned = _isUnsigned || a._isUnsigned;
        bool tNegative = _isNegative || a._isNegative; 
        bool tErr = _isErr || a._isErr;

        if (_isNegative == false && a._isNegative == false)
        {
            tv = (_value | a._value);
        }
        else if (_isNegative == false && a._isNegative == true)
        {
            long t2 = a._value * -1;
            long t3 = _value | t2;
            tv = t3 * -1;
        }
        else if (_isNegative == true && a._isNegative == false)
        {
            long t1 = _value * -1;
            long t3 = t1 | a._value;
            tv = t3 * -1;
        }
        else //if (_isNegative == true && a._isNegative == true)
        {
            long t1 = _value * -1;
            long t2 = a._value * -1;
            long t = (t1 & t2); 
            tv = t * -1;
        }

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }


    PPCtrlExprResult operator^(PPCtrlExprResult a)
    {
        if (_isUnsigned || a.isUnsigned())
        {
            promote();
            a.promote();
        } 
 
        unsigned long tv;
        bool tUnsigned = _isUnsigned | a._isUnsigned;
        bool tNegative = _isNegative ^ a._isNegative;;
        bool tErr = _isErr || a._isErr;

        if (_isNegative == false && a._isNegative == false)
        {
            tv = (_value ^ a._value);
        }
        else if (_isNegative == false && a._isNegative == true)
        {
            long t2 = a._value * -1;
            long t3 = _value ^ t2;
            tv = t3 * -1;
        }
        else if (_isNegative == true && a._isNegative == false)
        {
            long t1 = _value * -1;
            long t3 = t1 ^ a._value;
            tv = t3 * -1;
        }
        else //if (_isNegative == true && a._isNegative == true)
        {
            long t1 = _value * -1;
            long t2 = a._value * -1;
            long t = (t1 ^ t2); 
            tv = t;
        }

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }

    PPCtrlExprResult operator&&(const PPCtrlExprResult& a)
    {
        unsigned long tv;
        bool tUnsigned = false;
        bool tNegative = false;
        bool tErr = _isErr || a._isErr;

        tv = (_value != 0) && (a._value !=0);

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }


    PPCtrlExprResult operator||(const PPCtrlExprResult& a)
    {
        unsigned long tv;
        bool tUnsigned = false;
        bool tNegative = false;
        bool tErr = _isErr || a._isErr;

        tv = (_value != 0) || (a._value !=0);

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }


    PPCtrlExprResult operator~()
    {
        unsigned long tv;
        bool tUnsigned = _isUnsigned;
        bool tNegative = false;
        bool tErr = _isErr; 
       
        long t = _value; 
        if (_isNegative)
        {
            t = t * -1;
        }
        t = ~t;
        
        if (t>0)
        {
            tv = t;
            tNegative = false;
        }
        else
        {
            tv = -1 * t;
            tNegative = true;
        }

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }


    PPCtrlExprResult& operator=(const unsigned long v)
    {
        _value = v;
        return (*this);
    }

    PPCtrlExprResult& operator=(const PPCtrlExprResult &a)
    {
        if (this == &a)
        {
            return (*this);
        }

        _value = a._value;
        _isNegative = a._isNegative;
        _isUnsigned = a._isUnsigned;
        _isErr = a._isErr;

        return (*this);
    }

    friend ostream& operator<<(ostream &out, PPCtrlExprResult &pp);

    void setNegative(bool f) { _isNegative = f; }
    void setUnsigned(bool f) { _isUnsigned = f; }
    void setErr(bool f) { _isErr = f; }
    void setValue(unsigned long v) { _value = v; }
    void reset() { _value=0; _isNegative=false; _isUnsigned=false; _isErr=false;}

    bool isNegative() { return _isNegative; }
    bool isUnsigned() { return _isUnsigned; }
    bool isErr() { return _isErr; }
    unsigned long value() { return _value; }

  private:
    unsigned long _value;
    bool          _isNegative;
    bool          _isUnsigned;
    bool          _isErr;
};

ostream& operator<<(ostream &out, PPCtrlExprResult &pp)
{
    if (pp._isErr)
    {
        out << "error";
        return out;
    }

    if (pp._isUnsigned)
    {
        unsigned long t; 
        if (pp._isNegative)
        {
            t = pp._value * -1;
        }
        else
        {
            t = pp._value;
        }
        out << t << "u";
    }
    else
    {
        long t = pp._value;
        if (pp._isNegative)
            out << t*-1;
        else
            out << t;
    }
    return out;
}


class PPCtrlExprEvaluator
{
  public:

    vector<PostToken>::iterator _start;
    vector<PostToken>::iterator _end;
    vector<PostToken>::iterator _idx;

    PostToken _result;

    PPCtrlExprEvaluator(vector<PostToken>::iterator lstart, vector<PostToken>::iterator lend)
        : _start(lstart), _end(lend), _idx(lstart)
    {
    }

    ~PPCtrlExprEvaluator()
    {
    }

    void reset()
    {
    }

    PPCtrlExprResult eval_primary ()
    {

        PPCtrlExprResult term1 = 0;
        if (_idx->type == PT_LITERAL)
        {
            // skip all array type
            if (_idx->size > 1)
            {
                ++_idx;
                term1.setErr(true);
                return term1;
            }

            if (_idx->ltype == FT_SIGNED_CHAR)
            {
                char *v = (char*)_idx->data;
                term1 = *v;
            }
            else if (_idx->ltype == FT_SHORT_INT)
            {
                short int* v = (short int*)_idx->data;
                term1 = *v;
            }
            else if (_idx->ltype == FT_INT)
            {
                int *v = (int*)_idx->data;
                term1 = *v;
            }
            else if (_idx->ltype == FT_LONG_INT)
            {
                long int* v = (long int*)_idx->data;
                term1 = *v;

            }
            else if (_idx->ltype == FT_LONG_LONG_INT)
            {   
                long long int* v = (long long int*)_idx->data;
                term1 = *v;
            }
            else if (_idx->ltype == FT_UNSIGNED_CHAR)
            {
                unsigned char* v = (unsigned char*)_idx->data;
                term1 = *v;
                term1.setUnsigned(true);
            }
            else if (_idx->ltype == FT_UNSIGNED_SHORT_INT)
            {
                unsigned short int* v = (unsigned short int*)_idx->data;
                term1 = *v;
                term1.setUnsigned(true);
            }
            else if (_idx->ltype == FT_UNSIGNED_INT)
            {
                unsigned int* v = (unsigned int*)_idx->data;
                term1 = *v;
                term1.setUnsigned(true);
            }
            else if (_idx->ltype == FT_UNSIGNED_LONG_INT)
            {
                unsigned long int* v = (unsigned long int*)_idx->data;
                term1 = *v;
                term1.setUnsigned(true);
            }
            else if (_idx->ltype == FT_UNSIGNED_LONG_LONG_INT)
            {
                unsigned long long int* v = (unsigned long long int*)_idx->data;
                term1 = *v;
                term1.setUnsigned(true);
            }
            else if (_idx->ltype == FT_WCHAR_T)
            {
                wchar_t* v = (wchar_t*)_idx->data;
                term1 = *v;
            }
            else if (_idx->ltype == FT_CHAR)
            {
                char* v = (char*)_idx->data;
                term1 = *v;
            }
            else if (_idx->ltype == FT_CHAR16_T)
            {
                char16_t* v = (char16_t*)_idx->data;
                term1 = *v;
                term1.setUnsigned(true);
            }
            else if (_idx->ltype == FT_CHAR32_T)
            {
                char32_t* v = (char32_t*)_idx->data;
                term1 = *v;
                term1.setUnsigned(true);
            }
            else if (_idx->ltype == FT_BOOL)
            {
                throw PPCtrlExprEvalException("error");
            }
            else if (_idx->ltype == FT_FLOAT)
            {
                throw PPCtrlExprEvalException("error");
            }
            else if (_idx->ltype == FT_DOUBLE)
            {
                throw PPCtrlExprEvalException("error");
            }
            else if (_idx->ltype == FT_LONG_DOUBLE)
            {
                throw PPCtrlExprEvalException("error");
            }
            else
            {
                throw PPCtrlExprEvalException("error");
            }
            ++_idx;
            return term1;
        }
        else if (_idx->type == PT_OP_LPAREN )
        {
            _idx++;
            term1 = evalCtrlExpr();
            if (_idx->type == PT_OP_RPAREN)
            {
                _idx++;
            }
            else
            {
                throw PPCtrlExprEvalException("error");
            }
            return term1;
        }
        else if (_idx->type == PT_SIMPLE || (_idx->type >= PT_KW_ALIGNAS && _idx->type<=PT_KW_WHILE))
        {
            if (_idx->source == "defined")
            {
                _idx++;
                if (_idx->type == PT_OP_LPAREN)
                {
                    _idx++;
                    if (PA3Mock_IsDefinedIdentifier(_idx->source))
                    {
                        term1 = 1;
                    }
                    else
                    {
                        term1 = 0;
                    }
                    _idx++;

                    if (_idx->type == PT_OP_RPAREN)
                    {
                        _idx++;
                    }
                    else
                    {
                        throw PPCtrlExprEvalException("error");
                    }
                }
                else
                {
                    if (PA3Mock_IsDefinedIdentifier(_idx->source))
                    {
                        term1 = 1;
                    }
                    else
                    {
                        term1 = 0;
                    }
                    _idx++;
                }
            }
            else if (_idx->type == PT_KW_TRUE)
            {
                term1 = 1;
                _idx++;
            }
            else if (_idx->type == PT_KW_FALSE)
            {
                term1 = 0;
                _idx++;
            }
            else 
            {
                _idx++;
                term1 = 0;
            }
        }
        else
        {
             throw PPCtrlExprEvalException("error");
        }
        return term1;
    }
    
    
    PPCtrlExprResult eval_unary ()
    {
        PPCtrlExprResult term1, term2;
        // while (_idx != _end)
        // {
            if (_idx->type == PT_OP_PLUS)
            {
                _idx++;
                term1 = eval_unary (); 
            }
            else if (_idx->type == PT_OP_MINUS)
            {
                _idx++;
                term2 = eval_unary (); 
                PPCtrlExprResult temp(1,true/*isNegative*/);
                term1 = temp * term2;
            }
            else if (_idx->type == PT_OP_LNOT)
            {
                _idx++;
                term2 = eval_unary();
                PPCtrlExprResult temp(0);
                term1 = temp == term2;; 
            }
            else if (_idx->type == PT_OP_COMPL)
            {
                _idx++;
                term2 = eval_unary();
                term1 = ~term2;
            }
            else
            {
                term1 = eval_primary ();
                return term1;
            }
        //} 
        return term1;
    }
    
    
    PPCtrlExprResult eval_multiplicative ()
    {
        vector<PPCtrlExprResult> plist;
        vector<EPostTokenType>   tlist;

        PPCtrlExprResult term1, term2;
        term1 = eval_unary ();

        //while (_idx != _end)
        //{
        //    if (_idx->type == PT_OP_STAR)
        //    {
        //        _idx++;
        //        term2 = eval_unary (); 
        //        term1 = (term1 * term2);
        //    }
        //    else if (_idx->type == PT_OP_DIV)
        //    {
        //        _idx++;
        //        term2 = eval_unary (); 
        //        term1 = (term1 / term2);
        //    }
        //    else if (_idx->type == PT_OP_MOD)
        //    {
        //        _idx++;
        //        term2 = eval_unary ();
        //        term1 = (term1 % term2);
        //    }
        //    else
        //    {
        //        break;
        //    }
        //} 
        bool isPromote = term1.isUnsigned();
        while (_idx != _end)
        {
            if (_idx->type == PT_OP_STAR)
            {
                _idx++;
                term2 = eval_unary (); 
                //tlist.push_back(PT_OP_STAR);
                // plist.push_back(term2);
                isPromote = isPromote || term2.isUnsigned();
                // term2 = eval_unary (); 
                if (isPromote)
                {
                    term1.promote();
                    term2.promote();
                }
                term1 = (term1 * term2);
            }
            else if (_idx->type == PT_OP_DIV)
            {
                _idx++;
                term2 = eval_unary (); 
                //tlist.push_back(PT_OP_DIV);
                //plist.push_back(term2);
                isPromote = isPromote || term2.isUnsigned();
                // term2 = eval_unary (); 
                if (isPromote)
                {
                    term1.promote();
                    term2.promote();
                }
                term1 = (term1 / term2);
            }
            else if (_idx->type == PT_OP_MOD)
            {
                _idx++;
                term2 = eval_unary (); 
                //tlist.push_back(PT_OP_MOD);
                //plist.push_back(term2);
                isPromote = isPromote || term2.isUnsigned();
                //term2 = eval_unary ();
                if (isPromote)
                {
                    term1.promote();
                    term2.promote();
                }
                term1 = (term1 % term2);
            }
            else
            {
                break;
            }
        }

        // if (isPromote)
        // {
        //     term1.promote();
        // }

        // for (unsigned i=0; i<plist.size(); i++)
        // {
        //     if (isPromote)
        //     {
        //         plist[i].promote();
        //     }

        //     if (tlist[i] == PT_OP_STAR)
        //         term1 = term1 * plist[i];
        //     else if (tlist[i] == PT_OP_DIV)
        //         term1 = term1 / plist[i];
        //     else
        //         term1 = term1 % plist[i];
        // }
        return term1;
    }
    
    
    PPCtrlExprResult eval_additive ()
    {
        PPCtrlExprResult term1, term2;
        term1 = eval_multiplicative ();
        while (_idx != _end)
        {
            if (_idx->type == PT_OP_PLUS)
            {
                _idx++;
                term2 = eval_multiplicative (); 
                term1 = (term1 + term2);
            }
            else if (_idx->type == PT_OP_MINUS)
            {
                _idx++;
                term2 = eval_multiplicative (); 
                term1 = (term1 - term2);
            }
            else
            {
                break;
            }
        } 
        return term1;
    }
    
    PPCtrlExprResult eval_shift ()
    {
        PPCtrlExprResult term1, term2;
        term1 = eval_additive ();
        while (_idx != _end)
        {
            if (_idx->type == PT_OP_LSHIFT)
            {
                _idx++;
                term2 = eval_additive (); 
                term1 = (term1 << term2);
            }
            else if (_idx->type == PT_OP_RSHIFT)
            {
                _idx++;
                term2 = eval_additive (); 
                term1 = (term1 >> term2);
            }
            else
            {
                break;
            }
        } 
        return term1;
    }
    
    PPCtrlExprResult eval_relational ()
    {
        PPCtrlExprResult term1, term2;
        term1 = eval_shift ();
        while (_idx != _end)
        {
            if (_idx->type == PT_OP_LT)
            {
                _idx++;
                term2 = eval_shift (); 
                term1 = (term1 < term2);
            }
            else if (_idx->type == PT_OP_GT)
            {
                _idx++;
                term2 = eval_shift (); 
                term1 = (term1 > term2);
            }
            else if (_idx->type == PT_OP_LE)
            {
                _idx++;
                term2 = eval_shift (); 
                term1 = (term1 <= term2);
            }
            else if (_idx->type == PT_OP_GE)
            {
                _idx++;
                term2 = eval_shift (); 
                term1 = (term1 >= term2);
            }
            else
            {
                break;
            }
        } 
        return term1;
    }
    
    PPCtrlExprResult eval_equality ()
    {
        PPCtrlExprResult term1, term2;
        term1 = eval_relational ();
        while (_idx != _end)
        {
            if (_idx->type == PT_OP_EQ)
            {
                _idx++;
                term2 = eval_relational (); 
                term1 = (term1 == term2);
            }
            else if (_idx->type == PT_OP_NE)
            {
                _idx++;
                term2 = eval_relational (); 
                term1 = (term1 != term2);
            }
            else
            {
                break;
            }
        } 
        return term1;
    }
    
    PPCtrlExprResult eval_and ()
    {   
        PPCtrlExprResult term1, term2;
        term1 = eval_equality ();
        while (_idx != _end)
        {
            if (_idx->type == PT_OP_AMP)
            {
                _idx++;
                term2 = eval_equality (); 
                term1 = term1 & term2;
            }
            else
            {
                break;
            }
        } 
        return term1;
    }
    
    PPCtrlExprResult eval_exclusive_or ()
    {
        PPCtrlExprResult term1, term2;
        term1 = eval_and ();
        while (_idx != _end)
        {
            if (_idx->type == PT_OP_XOR)
            {
                _idx++;
                term2 = eval_and (); 
                term1 = term1 ^ term2;
            }
            else
            {
                break;
            }
        } 
        return term1;
    }
    
    PPCtrlExprResult eval_inclusive_or ()
    {
        PPCtrlExprResult term1, term2;
        term1 = eval_exclusive_or ();
        while (_idx != _end)
        {
            if (_idx->type == PT_OP_BOR)
            {
                _idx++;
                term2 = eval_exclusive_or (); 
                term1 = term1 | term2;
            }
            else
            {
                break;
            }
        } 
        return term1;

    }
    
    PPCtrlExprResult eval_logical_and ()
    {
        bool foundZero = false; 
        PPCtrlExprResult term1, term2, r;
        term1 = eval_inclusive_or();
        
        while (_idx != _end)
        {
            if (_idx->type == PT_OP_LAND)
            {
                if (term1.value()==0 || term1.isErr()==true) 
                {
                    r = term1 && PPCtrlExprResult(0);
                    foundZero = true;
                }
                _idx++;
                term2 = eval_inclusive_or(); 
                term1 = term1 && term2;
                // if (foundZero==false && (term1.value()==0 || term1.isErr()==true)) 
                // {
                //     r = term1;
                //     foundZero = true;
                // }
            }
            else
            {
                break;
            }
        } 
        if (foundZero)
            return r;
        else
            return term1;
    }
    
    PPCtrlExprResult eval_logical_or ()
    {
        bool foundOne = false;
        PPCtrlExprResult term1, term2, r; 
        term1 = eval_logical_and ();
        while (_idx != _end)
        {
            if ( _idx->type == PT_OP_LOR )
            {
                if (foundOne==false && (term1.value()!=0 || term1.isErr()))
                {
                    r = term1 || PPCtrlExprResult(1);
                    foundOne = true;
                }

                _idx++;
                term2 = eval_logical_and();
                term1 = term1 || term2;
                // if (foundOne==false && (term1.value()!=0 || term1.isErr()))
                // {
                //     r = term1;
                //     foundOne = true;
                // }
            }
            else
            {
                break;
            }
        }
        if (foundOne)
            return r;
        else
            return term1;
    }
    
    PPCtrlExprResult evalCtrlExpr()
    {
        PPCtrlExprResult term1, term2, term3;
        term1 = eval_logical_or();     

        if (_idx->type == PT_OP_QMARK)
        {
            _idx++; // skip OP_QMARK
            term2 = evalCtrlExpr();
            if (_idx->type == PT_OP_COLON )
            {
                _idx++;
                term3 = evalCtrlExpr();
            }
        
            PPCtrlExprResult zero(0);

            if (term1.isErr()) 
            {
                return term1;
            }

            if (term1.value() != 0)
            {
                if (term3.isUnsigned())
                {
                    term2.setUnsigned(true);
                }
                return term2;
            }
            else
            {
                if (term2.isUnsigned())
                {
                    term3.setUnsigned(true);
                }
                return term3;
            }
        }
        else
        {
            return term1;
        }
    }

    void startEval()
    {
        try 
        {
            if (_idx == _end)
            {
                // empty line, do nothing
                return;
            }
 
            PPCtrlExprResult result = evalCtrlExpr();
            if (_idx != _end)
            {
                throw PPCtrlExprEvalException("error");
            }
            else
            {
                cout << result << endl;
            }
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
    }
};


#ifdef PA3
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

        // PA2 start
        PostTokenizer postTokenizer(ppTokenizer._elst);         
        postTokenizer.parse();

        // PA3 start
        vector<PostToken>::iterator it = postTokenizer._tokens.begin(); 
        vector<PostToken>::iterator lstart=it, lend; 
        while (it != postTokenizer._tokens.end())
        {
            if (it != lstart)
            {
                if (it->type == PT_NEWLINE)
                {
                    PPCtrlExprEvaluator peval(lstart, it);
                    peval.startEval();
                    it++;
                    lstart = it;
                    continue;
                }
            } 
            else
            {
                if (it->type == PT_NEWLINE)
                {
                    it++;
                    lstart = it;
                    continue;
                }
                else if (it->type == PT_EOF)
                {
                    cout << "eof" << endl;
                    break;
                }
            }
            it++;
        }

    }
    catch (exception& e)
    {
        cerr << "ERROR: " << e.what() << endl;
        return EXIT_FAILURE;
    }
}
#endif
