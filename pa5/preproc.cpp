// (C) 2013 CPPGM Foundation www.cppgm.org.  All rights reserved.

#ifndef PA5
#pragma once
#endif  

#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>

#include <list>
#include <string>
#include "utf8.cpp"
#include "utf16.cpp" 
#include "pptoken.cpp"
#include "posttoken.cpp"
#include "ctrlexpr.cpp"
#include "macro.cpp"


using namespace std;

// // For pragma once implementation:
// // system-wide unique file id type `PA5FileId`
// typedef pair<unsigned long int, unsigned long int> PA5FileId;
// 
// // bootstrap system call interface, used by PA5GetFileId
// extern "C" long int syscall(long int n, ...) throw ();
// 
// // PA5GetFileId returns true iff file found at path `path`.
// // out parameter `out_fileid` is set to file id
// bool PA5GetFileId(const string& path, PA5FileId& out_fileid)
// {
// 	struct
// 	{
// 			unsigned long int dev;
// 			unsigned long int ino;
// 			long int unused[16];
// 	} data;
// 
// 	int res = syscall(4, path.c_str(), &data);
// 
// 	out_fileid = make_pair(data.dev, data.ino);
// 
// 	return res == 0;
// }
// 
// // OPTIONAL: Also search `PA5StdIncPaths` on `--stdinc` command-line switch (not by default)
// vector<string> PA5StdIncPaths =
// {
//     "/usr/include/c++/4.7/",
//     "/usr/include/c++/4.7/x86_64-linux-gnu/",
//     "/usr/include/c++/4.7/backward/",
//     "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/",
//     "/usr/local/include/",
//     "/usr/lib/gcc/x86_64-linux-gnu/4.7/include-fixed/",
//     "/usr/include/x86_64-linux-gnu/",
//     "/usr/include/"
// };

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

		out << "preproc " << nsrcfiles << endl;

		for (size_t i = 0; i < nsrcfiles; i++)
		{
			string srcfile = args[i+2];
			out << "sof " << srcfile << endl;

			// TODO: implement `preproc` as per PA5 description
			ifstream in(srcfile);
            ostringstream oss;
            oss << in.rdbuf();
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
            ppTokenizer._lineNo = 1;
            ppTokenizer.parse(uncTokens);
    
            DirectiveHandler directiveHandler(srcfile, ppTokenizer._elst);
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
                    if (concatStr.type == PT_INVALID)
                    {
                        throw DirectiveHandlerException("invalid string");
                    }
                    concatStr.emit(out);
                    concatStr.emit();
                    bPrevStr = false;
                    strCodes.clear();
                }

                if (pt.type == PT_INVALID)
                {
                    throw DirectiveHandlerException("invalid PostToken");
                }
                pt.emit(out);
                pt.emit();
            }  // end string concat
		}
	}
	catch (exception& e)
	{
		cerr << "ERROR: " << e.what() << endl;
		return EXIT_FAILURE;
	}
}

