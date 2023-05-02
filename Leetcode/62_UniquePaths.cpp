#include <bits/stdc++.h>
using namespace std;

//Memoization
class Solution {
public:
    
    int cnt;
	int uniquePathsHelper(int i, int j, int m, int n, vector<vector<int>> &dp){
		if (i==m-1&&j==n)
		{   
			cnt++;
			return 1;
		}
		if (i>=m || j>=n)
		{
			return 0;
		}
		else {
			if (dp[i][j]==-1)
			{
				return dp[i][j] = uniquePathsHelper(i+1,j,m,n,dp) +  uniquePathsHelper(i,j+1,m,n,dp);

			}
			else{
				return dp[i][j];
			}
		
		}}
    int uniquePaths(int m, int n) {
    	int i=0;
    	int j=0;
    	int cnt = 0;
    	vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return uniquePathsHelper( i, j, m, n, dp);
    }
};

class SolutionDP {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for (int i = 1; i < m; ++i)
        {
        	dp[i][0] = 1;
        }
        for (int i = 1; i < n; ++i)
        {
        	dp[0][i] = 1;
        }
        for (int i = 1; i < m; ++i)
        {
        	for (int j = 1; j < n; ++j)
        	{
        		dp[i][j] = dp[i-1][j] + dp[i][j-1];
        	}
        }
        return dp[m-1][n-1];
    }
};