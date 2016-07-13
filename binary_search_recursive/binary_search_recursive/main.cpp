//
//  main.cpp
//  binary_search_recursive
//
//  Created by Himanshu Ahuja on 13/07/16.
//  Copyright © 2016 Himanshu Ahuja. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace::std;

long binSearchRec(vector<int> a, unsigned long start, unsigned long end, unsigned long key){
    if( start <= end )
    {
        unsigned long mid = (start + end)/2;
        if(a[mid] == key)
            return mid;
        else if(a[mid] > key)
            return binSearchRec (a, start, mid-1, key);
        else if(a[mid] <=key)
            return binSearchRec (a, mid+1, end, key);
        else
            return -1;
    }
    else
        return -1;
}

int main(int argc, const char * argv[]) {
    vector<int> a = {1,2,3,4,5,6,7,8,9,10,11,12};
    long ans = binSearchRec(a, 0, 11, 9);
    cout<<ans;
    
}
