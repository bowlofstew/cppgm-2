#include <vector>
#include <iostream>

using namespace std;

void swap( vector<int>& input, unsigned a, unsigned b) {
    // swap
    int tmp = input[a];             
    input[a] = input[b]; 
    input[b] = tmp;
    return;
}

unsigned int split_array (vector<int>& input, unsigned int first, unsigned int end) 
{
    unsigned int x = input[first];
    unsigned unknown;
    unsigned current_split = first;

    for (unknown = first+1 ; unknown < end; unknown++) {
         if (input[unknown] < x ) {
             current_split++;
             swap( input, current_split, unknown);
         } 
    }
    swap(input, first, current_split);
    return current_split;
}

//=================================================================
// start: the start index
// end: the index that's after the last inidex
// k can be 1 ~ end
//=================================================================
int get_order_k ( vector<int>& input , unsigned start, unsigned end, unsigned k ) 
{
    unsigned split_current = split_array(input, start, end);        
    unsigned idx = k-1;

    if (idx == split_current-start) 
    {
        return input[split_current];
    } 
    else if ( k > split_current-start) 
    {
        return get_order_k(input, split_current+1, end, k-(split_current-start+1));
    }
    else 
    {
        return get_order_k(input, start, split_current, k );
    }
}




void dump (const vector<int>& test) 
{
    for (unsigned i=0; i<test.size(); i++) {
        cout << test[i] << " ";
    }
    cout << endl;
}


int main (void) 
{

    vector<int> input;

    input.push_back(3);
    input.push_back(1);
    input.push_back(4);
    input.push_back(5);
    input.push_back(2);
   
    cout << "begin" << endl; 

    dump(input);

    // split_array(input,0,input.size());
    //
    cout << get_order_k(input,0,input.size(),5) << endl; 

    dump(input);
    
    return 0;
}







