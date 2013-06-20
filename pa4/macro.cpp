// (C) 2013 CPPGM Foundation www.cppgm.org.  All rights reserved.

#ifndef PA4
#pragma once
#endif

#include <string>
#include "utf8.cpp"
#include "utf16.cpp"
#include "pptoken.cpp"
#include "posttoken.cpp"
#include "ctrlexpr.cpp"

using namespace std;

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
