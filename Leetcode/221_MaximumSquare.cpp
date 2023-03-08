#include <bits/stdc++.h>
using namespace std;
class Solution {
public:    
    int dfs(vector<vector<char>>& matrix, int row, int col, int &maximal, vector<vector<int>> &memo)
    { 
        if(row >= matrix.size() || col >= matrix[0].size() || matrix[row][col] == '0')
            return 0; 
        if(memo[row][col] > 0)
            return memo[row][col]; 
        
        int len1 = dfs(matrix, row+1, col, maximal, memo); 
        int len2 = dfs(matrix, row, col+1, maximal, memo); 
        int len3 = dfs(matrix, row+1, col+1, maximal, memo); 
                                   
        memo[row][col] = 1 + min(min(len1, len2), len3); 
        maximal = max(maximal, memo[row][col]); 
        return memo[row][col];             
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0; 
        int maximal = 0;   
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size())); 
        for(int row = 0; row < matrix.size(); row++)
            for(int col = 0; col < matrix[0].size(); col++) 
                if(matrix[row][col] =='1' && memo[row][col] == 0) // can be upper left corner of a square
                    dfs(matrix, row, col, maximal, memo);
        return maximal*maximal; 
    }
};