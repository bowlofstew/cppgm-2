#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

int main(int argc, char** argv) 
{

    if (argc != 3) {
        cout << "Usage: test <substr> <targetStr>" << endl;
        return -1;
    }

    string src ( argv[1] );
    string tar ( argv[2] );
    cout << "Test 6-4, search " << src << " in " << tar << endl;

    vector<int> bookArray( src.size(), 0 );
    for (unsigned i=1; i<bookArray.size(); ++i) {
        int prevBook = bookArray[i-1];
        if ( prevBook > 0 ) {
            if ( src[i] == src[ prevBook ] ) {
                bookArray[i] = prevBook + 1;
            }  
            else {
                // search for next compare index
                while (prevBook > 0) {
                     prevBook = bookArray[prevBook-1];                  
                     if (src[i] == src[prevBook]) {
                         bookArray[i] = prevBook + 1;
                         break;
                     }
                }
            }
        }
        else {
            if ( src[i] == src[0] ) {
                bookArray[i] = 1;
            }
        }
    }

    for (unsigned j=0; j<bookArray.size(); ++j) {
        cout << bookArray[j] << " "; 
    }
    cout << endl;

    //--- start to compare
    int sidx = 0; 
    int tidx = 0;
    int fidx = -1;

    cout << "---------------" << endl;
    cout << tar << endl;

    while ( tidx < tar.size() ) {
        if (src[sidx] == tar[tidx]) {
            if ( sidx == src.size()-1 ) {
                fidx = tidx - sidx;
                break;
            }
            ++sidx;
            ++tidx;
        }
        else {
            if (sidx == 0) {
                ++tidx;
                fidx = -1;
            } 
            else {
                sidx = bookArray[sidx-1];
            }
        }
    }

    cout << "Found at position : " << fidx << endl;
    return 0;
}





