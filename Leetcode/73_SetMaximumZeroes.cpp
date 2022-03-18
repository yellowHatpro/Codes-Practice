#include <bits/stdc++.h>
using namespace std;


//Bruteforce
class SolutionBruteforce {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==0){
               for (int x = 0; x < matrix.size(); ++x)
               {
                   if ((matrix[x][j]!=matrix[i][j])&& matrix[x][j]!=0)
                   {
                       matrix[x][j]=-1;
                   }
               }
               for (int y = 0; y < matrix[i].size(); ++y)
               {
                   if ((matrix[i][y]!=matrix[i][j])&& matrix[i][y]!=0)
                   {
                       matrix[i][y]=-1;
                   }
               }
            }
        }
    }
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j]==-1)
            {
                matrix[i][j]=0;
            }
        }
    }
    }
};

//Clever solution: Use the first element from the rows and columns to check whether the complete row or column will have 0 or not.
//In case of 0th row and 0th column, use a var for column to avoid clash between them.(Say 0th row doesnt has 0 but 0th column has 0, then matrix[0][0] will be 0, which is wrong)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0= 1;
        for (int i = 0; i < matrix.size(); ++i)
        {
            if (matrix[i][0]==0) 
            {   //Check for 0th column
                col0 =0;
            }
            for (int j = 1; j < matrix[i].size(); ++j)
            {   //Checking for other columns , leaving 0th col
                if (matrix[i][j]==0)
                {
                    matrix[0][j]=0; //marking first element of both row and col
                    matrix[i][0]=0;
                }
            }
        }

        for (int i = matrix.size()-1; i >= 0; i--)
        {
            if (col0==0)
            {
                matrix[i][0]=0;
            }
            for (int j = matrix[i].size(); j >=0; j--)
            {
                if (matrix[i][0]==0||matrix[0][j]==0) 
                {
                    matrix[i][j]=0;
                }
            }
        }

    }
};


