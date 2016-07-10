#include <iostream>
#include <vector>

using namespace::std;

vector<int> spiralOrder(const vector<vector<int>> &A) {
    vector<int> result;
    unsigned long row = A.size();
    unsigned long col = A[0].size();
    unsigned long T = 0, L=0;
    unsigned long B = row - 1;
    unsigned long R = col - 1;
    int dir = 0;
    unsigned long i;
    
    
    while (T<=B && R>=L)
    {
        
        if(dir == 0)
        {
            for (i = L ; i<=R; i++)
                result.push_back(A[T][i]);
            T++;
            dir = 1;
        }
        
        else if(dir == 1)
        {
            for (i = T; i<=B; i++)
                result.push_back(A[i][R]);
            R--;
            dir = 2;
        }
        
        else if(dir == 2)
        {
            for(i=R; i>=L; i--)
                result.push_back(A[B][i]);
            B--;
            dir = 3;
        }
        
        else if(dir == 3 )
        {
            for(i = B; i>=T; i--)
                result.push_back(A[i][L]);
            L++;
            dir = 0;
        }
        
    }
    // DO STUFF HERE AND POPULATE result
    return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}


int main()
{
    const vector<vector <int>> V = {{1,2,3,4},{5,6,7,8},{9, 10, 11, 12}};
    vector<int> result = spiralOrder (V);
    for (int j = 0; j<result.size(); j++)
        printf("%d", result[j]);
}
