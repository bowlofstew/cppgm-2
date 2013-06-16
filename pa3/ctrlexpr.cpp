// (C) 2013 CPPGM Foundation www.cppgm.org.  All rights reserved.

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
        : _value(v), _isNegative(isNegative), _isUnsigned(isUnsigned)  
    {
        _isErr = false;
    }

    ~PPCtrlExprResult() 
    {
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

    PPCtrlExprResult operator*(const PPCtrlExprResult& a)
    {
        unsigned long tv;
        bool tUnsigned;
        bool tNegative;
        bool tErr;

        tUnsigned = _isUnsigned || a._isUnsigned;
        tNegative = _isNegative || a._isNegative;
        tErr = _isErr || a._isErr;
        tv = _value * a._value;

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }

    PPCtrlExprResult operator/(const PPCtrlExprResult& a)
    {
        unsigned long tv;
        bool tUnsigned;
        bool tNegative;
        bool tErr;

        tUnsigned = _isUnsigned || a._isUnsigned;
        tNegative = _isNegative || a._isNegative;
        tErr = _isErr || a._isErr;

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

        tUnsigned = _isUnsigned || a._isUnsigned;
        tNegative = _isNegative || a._isNegative;
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

        if (a._isNegative || a._value > 64)
        {
            tErr = true;
            tv = 0;
        }
        else
        {
            tv = _value >> a._value;
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

        if (a._isNegative || a._value > 64)
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


    PPCtrlExprResult operator>(const PPCtrlExprResult& a)
    {
        unsigned long tv;
        bool tUnsigned = false;
        bool tNegative = false;
        bool tErr = _isErr || a._isErr;

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

    PPCtrlExprResult operator>=(const PPCtrlExprResult& a)
    {
        unsigned long tv;
        bool tUnsigned = false;
        bool tNegative = false;
        bool tErr = _isErr || a._isErr;

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

    PPCtrlExprResult operator<(const PPCtrlExprResult& a)
    {
        unsigned long tv;
        bool tUnsigned = false;
        bool tNegative = false;
        bool tErr = _isErr || a._isErr;

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

    PPCtrlExprResult operator<=(const PPCtrlExprResult& a)
    {
        unsigned long tv;
        bool tUnsigned = false;
        bool tNegative = false;
        bool tErr = _isErr || a._isErr;

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


    PPCtrlExprResult operator!=(const PPCtrlExprResult& a)
    {
        unsigned long tv;
        bool tUnsigned = false;
        bool tNegative = false;
        bool tErr = _isErr || a._isErr;

        if (_value==0 && a._value==0)
        {
            tv = 0;
        }
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

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }


    PPCtrlExprResult operator==(const PPCtrlExprResult& a)
    {
        unsigned long tv;
        bool tUnsigned = false;
        bool tNegative = false;
        bool tErr = _isErr || a._isErr;

        if (_value==0 && a._value==0)
        {
            tv = 1;
        }
        else if (_isNegative == false && a._isNegative == false)
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

        return PPCtrlExprResult(tv, tNegative, tUnsigned, tErr);
    }





  private:
    unsigned long _value;
    bool          _isNegative;
    bool          _isUnsigned;
    bool          _isErr;
};



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

    unsigned long long eval_primary ()
    {

        if (_idx->type == PT_LITERAL)
        {
            unsigned long long term1 = 0;

            // skip all array type
            if (_idx->size > 1)
            {
                ++_idx;
                return 0;
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
            }
            else if (_idx->ltype == FT_UNSIGNED_SHORT_INT)
            {
                unsigned short int* v = (unsigned short int*)_idx->data;
                term1 = *v;
            }
            else if (_idx->ltype == FT_UNSIGNED_INT)
            {
                unsigned int* v = (unsigned int*)_idx->data;
                term1 = *v;
            }
            else if (_idx->ltype == FT_UNSIGNED_LONG_INT)
            {
                unsigned long int* v = (unsigned long int*)_idx->data;
                term1 = *v;
            }
            else if (_idx->ltype == FT_UNSIGNED_LONG_LONG_INT)
            {
                unsigned long long int* v = (unsigned long long int*)_idx->data;
                term1 = *v;
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
            }
            else if (_idx->ltype == FT_CHAR32_T)
            {
                char32_t* v = (char32_t*)_idx->data;
                term1 = *v;
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
            unsigned long long term1;
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
            unsigned long long term1;
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
            return term1;
        }
        return 0;
    }
    
    
    unsigned long long eval_unary ()
    {
        unsigned long long term1, term2;
        while (_idx != _end)
        {
            if (_idx->type == PT_OP_PLUS)
            {
                _idx++;
                term1 = eval_unary (); 
            }
            else if (_idx->type == PT_OP_MINUS)
            {
                _idx++;
                term2 = eval_unary (); 
                term1 = -1 * term2; 
            }
            else if (_idx->type == PT_OP_LNOT)
            {
                _idx++;
                term2 = eval_unary();
                term1 = !term2; 
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
        } 
        return term1;
    }
    
    
    unsigned long long eval_multiplicative ()
    {
        unsigned long long term1, term2;
        term1 = eval_unary ();
        while (_idx != _end)
        {
            if (_idx->type == PT_OP_STAR)
            {
                _idx++;
                term2 = eval_unary (); 
                term1 = (term1 * term2);
            }
            else if (_idx->type == PT_OP_DIV)
            {
                _idx++;
                term2 = eval_unary (); 
                term1 = (term1 / term2);
            }
            else if (_idx->type == PT_OP_MOD)
            {
                _idx++;
                term2 = eval_unary ();
                term1 = (term1 % term2);
            }
            else
            {
                break;
            }
        } 
        return term1;
    }
    
    
    unsigned long long eval_additive ()
    {
        unsigned long long term1, term2;
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
    
    unsigned long long eval_shift ()
    {
        unsigned long long term1, term2;
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
    
    unsigned long long eval_relational ()
    {
        unsigned long long term1, term2;
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
    
    unsigned long long eval_equality ()
    {
        unsigned long long term1, term2;
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
    
    unsigned long long eval_and ()
    {   
        unsigned long long term1, term2;
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
    
    unsigned long long eval_exclusive_or ()
    {
        unsigned long long term1, term2;
        term1 = eval_and ();
        while (_idx != _end)
        {
            if (_idx->type == PT_OP_LAND)
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
    
    unsigned long long eval_inclusive_or ()
    {
        unsigned long long term1, term2;
        term1 = eval_exclusive_or ();
        while (_idx != _end)
        {
            if (_idx->type == PT_OP_LAND)
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
    
    unsigned long long eval_logical_and ()
    {
        unsigned long long term1, term2;
        term1 = eval_inclusive_or();
        while (_idx != _end)
        {
            if (_idx->type == PT_OP_LAND)
            {
                _idx++;
                term2 = eval_inclusive_or(); 
                term1 = term1 && term2;
            }
            else
            {
                break;
            }
        } 
        return term1;
    }
    
    unsigned long long eval_logical_or ()
    {
        unsigned long long term1, term2; 
        term1 = eval_logical_and ();
        while (_idx != _end)
        {
            if ( _idx->type == PT_OP_LOR )
            {
                _idx++;
                term2 = eval_logical_and();
                term1 = term1 || term2;
            }
            else
            {
                break;
            }
        }
        return term1;
    }
    
    unsigned long long evalCtrlExpr()
    {
        unsigned long long term1, term2, term3;
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

            return (term1 ? term2 : term3);
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
 
            unsigned long long result = evalCtrlExpr();
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

