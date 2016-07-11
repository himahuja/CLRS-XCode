//
//  main.cpp
//  Bubble_Sort
//
//  Created by Himanshu Ahuja on 11/07/16.
//  Copyright © 2016 Himanshu Ahuja. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace :: std;
vector<int> bubbleSort(vector<int> A, unsigned long n)
{
    int k, i, flag;
    for(k = 0; k <= n-2 ; k++){
        flag = 0 ;
        for(i = 0; i <= n-2-k; i++)
        {
            if (A[i]>A[i+1])
            {
                swap (A[i], A[i+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
        cout<<"\nList after pass "<<k+1<<" is:";
        for(int j=0; j<=n-1; j++)
            cout<<A[j]<<" ";
    }
    return A;
}
int main() {
    vector<int> A = {2, 7, 3 , 4 , 1 , 5 };
    
    vector<int> result = bubbleSort(A, A.size());
    cout<<"\n";
    for  ( int i = 0; i < result.size(); i++)
        cout<<result[i]<<" ";
    return 0;

}


