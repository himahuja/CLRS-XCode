//
//  main.cpp
//  Insertion_Sort_Recursive
//
//  Created by Himanshu Ahuja on 13/07/16.
//  Copyright © 2016 Himanshu Ahuja. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits>

using namespace::std;

vector<int> merge(vector<int> c, int k)
{   c.push_back(INT_MAX);
    unsigned long n = c.size();
    unsigned long i = n - 2;
    while( k < c[i] && i != -1)
    {
         c[i+1]= c[i];
        i--;
    }
    c[i+1] = k;
    cout<<"\nSorted array on merge "<<c.size() - 1 <<" is:";
    for(int j=0; j<c.size(); j++)
        cout<<c[j]<<" ";
    return c;
}

vector<int> inSortRec (vector<int> a)
{
    unsigned long n  = a.size();
    if(n < 2 )
        return a;
    vector <int> b = a; b.pop_back(); //creating array b of size n-1
    vector<int> c = inSortRec(b);
    return merge (c, a[n - 1]);
    
}
int main(int argc, const char * argv[]) {
    vector<int> trial = {3,1,4,6, 8, 2, 78, 9, 3, 0, 1};
    vector<int> magic = inSortRec(trial);
    cout<<"\n";
    for(int i=0; i<magic.size(); i++)
        cout<<magic[i]<<" ";
}
