//
//  main.cpp
//  SelectionSort
//
//  Created by Himanshu Ahuja on 11/07/16.
//  Copyright © 2016 Himanshu Ahuja. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace :: std;

vector<int> selectionSort(vector<int> A, unsigned long n)
{
    int i, iMin, j, temp;
    for (i = 0; i <=n-2; i++){
        iMin = i;
        for (j = i+1; j <= n-1; j++)
        {
            if(A[j] < A[iMin])
            {
                iMin = j;
            }
        }
        temp = A[i];
        A[i] = A[iMin];
        A[iMin] = temp;
        cout<<"\nList after pass "<<i+1<<" is:";
        for(int k=0; k<=n-1; k++)
            cout<<A[k]<<" ";
    }
    
    return A;
}
int main() {
    
    vector<int> A = {1, 2, 3, 4 , 5 , 7};
    
    vector<int> result = selectionSort(A, A.size());
    cout<<"\n";
    for  ( int i = 0; i < result.size(); i++)
        cout<<result[i]<<" ";
    return 0;
}
