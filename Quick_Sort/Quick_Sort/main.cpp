//
//  main.cpp
//  Quick_Sort
//
//  Created by Himanshu Ahuja on 11/07/16.
//  Copyright © 2016 Himanshu Ahuja. All rights reserved.
//

#include <iostream>
#include <algorithm> 
#include <vector>

using namespace::std;

unsigned long partition (vector<int>& A, unsigned long start, unsigned long end){
    unsigned long pivot = A[end];
    unsigned long pIndex = start;
    for (unsigned long i = start; i < end; i++) //only to end-1 since
    {                                           //end is pivot
        if(A[i] <=  pivot)
        {
            swap(A[i], A[pIndex]);
            pIndex = pIndex + 1;
        }
    }
    swap(A[pIndex], A[end]);
    return pIndex;
}

void quickSort(vector<int>& A, unsigned long start, unsigned long end)
{
    if(start<end){
        unsigned long pIndex = partition(A, start, end);
        quickSort(A, start, pIndex - 1);
        quickSort(A, pIndex + 1, end);
    }
}

int main() {
    vector<int> A = { 3 ,6 , 9, 1, 2, 8, 5, 4, 7};
    quickSort(A, 0, A.size());
    cout<<"Sorted list is: ";
    for(int i=0; i<A.size(); i++)
    {
        cout<<A[i]<<" ";
    }
}
