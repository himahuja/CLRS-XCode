//
//  main.cpp
//  Insertion_Sort
//
//  Created by Himanshu Ahuja on 11/07/16.
//  Copyright © 2016 Himanshu Ahuja. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace :: std;

vector<int> insertionSort (vector<int> A, unsigned long n)
{
    int i, value, hole;
    for(i = 1; i <= n-1; i++)
    {
        value = A[i];
        hole = i;
        while ( hole>0 && value < A[hole - 1])
        {
            A[hole] = A[hole - 1];
            hole = hole - 1;
        }
        A[hole] = value;
        cout<<"\nList after pass "<<i<<" is:";
        for(int k=0; k<=n-1; k++)
            cout<<A[k]<<" ";
    }
    
    
    return A;
}


int main() {
    vector<int> A = {2, 7, 3 , 4 , 1 , 5 };
    
    vector<int> result = insertionSort(A, A.size());
    cout<<"\n";
    for  ( int i = 0; i < result.size(); i++)
        cout<<result[i]<<" ";
    return 0;

}
