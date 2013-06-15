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


int evalCtrlExpr(vector<PostToken>::iterator it, vector<PostToken>::iterator tend)
{
    vector<PostToken>::iterator idx = it; 
    if (idx == tend)
    {
        return 0;
    }
    
    while (idx != tend)
    {
        EPostTokenType e = idx->type;    
        string s = idx->source;
        cout << PostTokenTypeToStringMap.at(e) << " " << s << endl;
        idx++;
    }
     
    return 1;
}


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
        evalCtrlExpr(postTokenizer._tokens.begin(), postTokenizer._tokens.end());
        
        
        
    }
    catch (exception& e)
    {
        cerr << "ERROR: " << e.what() << endl;
        return EXIT_FAILURE;
    }
}

