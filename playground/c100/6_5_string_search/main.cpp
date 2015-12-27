#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>


using namespace std;

int main(int argc, char** argv) 
{

    if (argc != 3) {
        cout << "Usage: test <substr> <targetStr>" << endl;
        return -1;
    }

    string src ( argv[1] );
    string tar ( argv[2] );
    cout << "Test 6-5, search " << src << " in " << tar << endl;

    map<char,int> idxMap;
    for (unsigned i=0; i<src.size(); ++i) 
    {
        idxMap[ src[i] ] = i;
    }


    //--- start to compare
    int sidx = src.size() - 1; 
    int tidx = 0;
    int fidx = -1;

    cout << "---------------" << endl;
    cout << tar << endl;

    while ( tidx < tar.size() && fidx < 0) 
    {
        for ( sidx=src.size()-1; sidx>=0; sidx--)
        {
            if ( src[sidx] != tar[tidx+sidx] ) 
            {
                map<char,int>::iterator it = idxMap.find( tar[tidx+sidx] );
                if (it != idxMap.end()) 
                {
                    if (it->second < sidx) {
                        tidx += sidx - it->second;
                    }
                    else {
                        tidx += (sidx+1);
                    }
                }
                else {
                    tidx += src.size();
                }
                break;
            }
            else {
                if (sidx == 0) {
                    fidx = tidx;
                    break;
                }
            }
        }
    }

    cout << "Found at position : " << tidx << endl;
    return 0;
}





