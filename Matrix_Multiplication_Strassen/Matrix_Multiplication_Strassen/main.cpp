//
//  main.cpp
//  Matrix_Multiplication_Strassen
//
//  Created by Himanshu Ahuja on 16/07/16.
//  Copyright © 2016 Himanshu Ahuja. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace::std;

struct index{
    unsigned long RStart, REnd, CStart, CEnd;
};

vector<vector<int>> matrixMultiplyStrassen (vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> Output, struct index indexA, struct index indexB, struct index indexC){
    unsigned long n = A.size();
    unsigned long j = 0, i = 0, k = 0, l = 0;
    
    ////////////////////////////PARTITIONING THE VECTORS///////////////////////////////
    unsigned long RmidA = (indexA.RStart + indexA.REnd)/2;
    unsigned long CmidA = (indexA.CStart + indexA.CEnd)/2;
    unsigned long RmidB = (indexB.RStart + indexB.REnd)/2;
    unsigned long CmidB = (indexB.CStart + indexB.CEnd)/2;
    
    struct index indexA11 = {indexA.RStart, RmidA, indexA.CStart, CmidA};
    struct index indexA12 = {indexA.RStart, RmidA, CmidA + 1, indexA.CEnd};
    struct index indexA21 = {RmidA + 1, indexA.REnd, indexA.CStart, CmidA};
    struct index indexA22 = {RmidA + 1, indexA.REnd, CmidA + 1, indexA.CEnd};
    struct index indexB11 = {indexB.RStart, RmidB, indexB.CStart, CmidB};
    struct index indexB12 = {indexB.RStart, RmidB, CmidB + 1, indexB.CEnd};
    struct index indexB21 = {RmidB + 1, indexB.REnd, indexB.CStart, CmidB};
    struct index indexB22 = {RmidB + 1, indexB.REnd, CmidB + 1, indexB.CEnd};
    
    vector<vector<int>> C (A.size(), vector<int> (A[indexA.RStart].size(), 0));
    
    
  

    
    
        
    vector<vector<int>> S1 ( A.size()/2, vector<int> ( A[indexA.RStart].size()/2, 0) );
    vector<vector<int>> S2 ( A.size()/2, vector<int> ( A[indexA.RStart].size()/2, 0) );
    vector<vector<int>> S3 ( A.size()/2, vector<int> ( A[indexA.RStart].size()/2, 0) );
    vector<vector<int>> S4 ( A.size()/2, vector<int> ( A[indexA.RStart].size()/2, 0) );
    vector<vector<int>> S5 ( A.size()/2, vector<int> ( A[indexA.RStart].size()/2, 0) );
    vector<vector<int>> S6 ( A.size()/2, vector<int> ( A[indexA.RStart].size()/2, 0) );
    vector<vector<int>> S7 ( A.size()/2, vector<int> ( A[indexA.RStart].size()/2, 0) );
    vector<vector<int>> S8 ( A.size()/2, vector<int> ( A[indexA.RStart].size()/2, 0) );
    vector<vector<int>> S9 ( A.size()/2, vector<int> ( A[indexA.RStart].size()/2, 0) );
    vector<vector<int>> S10 ( A.size()/2, vector<int> ( A[indexA.RStart].size()/2, 0) );
    
    
    for(i = 0; i <= RmidA; i++){
        for(j=0; j<=RmidA; j++){
            S1[
        }
    }
    
    

    return C;
}


int main() {
    vector<vector<int>> A = {{1,2,3,4},{2,3,4,5},{4,5,6,9}, {6,7,8,9}};
    vector<vector<int>> B = {{1,2,3,4},{2,3,4,5},{4,5,6,9}, {6,7,8,9}};
}
