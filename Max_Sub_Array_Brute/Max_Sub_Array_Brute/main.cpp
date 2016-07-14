//
//  main.cpp
//  Max_Sub_Array_Brute
//
//  Created by Himanshu Ahuja on 15/07/16.
//  Copyright © 2016 Himanshu Ahuja. All rights reserved.
//
// Brute force implementation of the Maximum Sub Array Problem

#include <iostream>
#include <vector>
#include <limits>

using namespace::std;

int main(int argc, const char * argv[]) {
    
    vector <int> A ={13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    unsigned long n = A.size();
    int sum;
    int moall = INT_MIN;
    unsigned long mindex = 0;
    vector<int> maxprofit(n, INT_MIN);
    vector<unsigned long> index(n, 0);
    for (unsigned long i = 0; i<=n-1; i++){
        sum = 0;
        for(unsigned long j = i; j <=n-1; j++){
            sum = sum + A[j];
            if(sum > maxprofit[i]){
                maxprofit[i]= sum;
                index[i] = j;
            }
        }
        if(maxprofit[i] > moall)
        {
            moall = maxprofit[i];
            mindex = i;
        }
    }
    
    for(int m = 0; m<=n-1; m++){
        cout<<maxprofit[m]<<" ";
    }
    
    cout<<"\n";
    
    for(unsigned long k = mindex; k<=index[mindex]; k++)
    {
        cout<<A[k]<<" ";
    }
    
    cout<<"\n"<<moall<<"\n";
}
