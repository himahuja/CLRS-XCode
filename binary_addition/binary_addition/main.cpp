//
//  main.cpp
//  binary_addition
//
//  Created by Himanshu Ahuja on 12/07/16.
//  Copyright © 2016 Himanshu Ahuja. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace::std;

vector<int> binaryAddition(vector<int> a, vector<int>b)
{
    vector<int> result;
    int c = 0;
    long i;
    for(i = a.size()-1 ; i != -1 ; i--){
        
        if( (a[i] && b[i] && c) || (!a[i] && !b[i] && c) || (!a[i] && b[i] && !c) || (!b[i] && a[i] && !c) )
            result.push_back(1);
        else
            result.push_back(0);
        
        if( (a[i] && b[i]) || (c && b[i]) || (a[i] && c) )
            c = 1;
        else
            c = 0;
    }
    result.push_back(c);
    return result;
}

int main(int argc, const char * argv[]) {
    // a and b should be of same size
    vector<int> a = {1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1};
    vector<int> b = {1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1};
    vector<int> result = binaryAddition(a, b);
    for(long i = result.size() - 1; i != -1 ; i--)
    {
        cout<<result[i]<<" ";
    }
}
