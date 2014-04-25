
#include "regexp.h"

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;


int test_simple_match (const char* pat, const char* ins) 
{
    Regexp regexp(pat);
    if (regexp.run(ins) < 0) {
        stringstream ss;
        ss << "In \"" << ins << "\"  " << "found no " << "\"" << pat << "\"" << endl;
        throw logic_error(ss.str().c_str());
    }
    else {
        cout << "PASS: found " << "\"" << pat << "\" in " << ins << endl;
    }
    return 1;
}

int test_simple_mismatch (const char* pat, const char* ins) 
{
    Regexp regexp(pat);
    if (regexp.run(ins) >= 0) {
        stringstream ss;
        ss << "In \"" << ins << "\"  " << "should found no " << "\"" << pat << "\"" << endl;
        throw logic_error(ss.str().c_str());
    }
    else {
        cout << "PASS: found no " << "\"" << pat << "\" in " << ins << endl;
    }
    return 1;
}

int main(int argc, char** args) {

    Regexp regexp("abc");

    test_simple_match("a", "a");
    test_simple_match("abc", "abc");
    test_simple_match("abc", "abcdefg");
    test_simple_match("abc", "123abcdefg");

}


