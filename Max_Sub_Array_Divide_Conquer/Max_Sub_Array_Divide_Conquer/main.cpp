//
//  main.cpp
//  Max_Sub_Array_Divide_Conquer
//
//  Created by Himanshu Ahuja on 15/07/16.
//  Copyright © 2016 Himanshu Ahuja. All rights reserved.
//

#include <iostream>
#include <limits>
#include <vector>
#include <time.h>

using namespace :: std;

//FIND THE MAXIMUM SUM IN THE SUBARRAY

int findMaxCrossSubArray(vector<int> &A, unsigned long low, unsigned long mid, unsigned long high){
    int leftSum = INT_MIN;
    int sum = 0;
    long i;
    
    for (i = mid; i>=low && i!= -1 ; i--){
        sum = sum + A[i];
        if (sum > leftSum)
            leftSum = sum;
    }
    int rightSum = INT_MIN;
    sum = 0;
    
    for ( i = mid+1; i<=high; i++){
        sum = sum + A[i];
        if( sum > rightSum)
            rightSum = sum;
    }
    
    return ( leftSum + rightSum );
    
}


int findMaxSubArray (vector<int> &A, unsigned long low, unsigned long high){
    if ( low == high )
        return A[low];
    unsigned long mid = (low+high)/2;
    int sumLeft = findMaxSubArray(A, low, mid);
    int sumRight = findMaxSubArray(A, mid+1, high);
    int sumCross =  findMaxCrossSubArray (A, low, mid, high);
    
    int sumMax = sumLeft >= sumRight ? ( sumLeft >= sumCross ? sumLeft : sumCross ) : ( sumRight >= sumCross ? sumRight : sumCross);
    return sumMax;
}


int main() {
    clock_t start = clock();
    vector <int> A ={13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int maxSum = findMaxSubArray(A, 0 , A.size() - 1);
    cout<<"Maximum sum is: "<<maxSum;
    clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTime elapsed in ms: %f \n", elapsed);
    return 0;
    
}
