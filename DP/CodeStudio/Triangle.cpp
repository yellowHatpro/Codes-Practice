#include <bits/stdc++.h>
using namespace std;

int f(int i,int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp){
    if (i==n) return triangle[i][j];
    if (dp[i][j]!=-1) return dp[i][j];
    int d = f(i+1,j,n,triangle,dp) + triangle[i][j];
    int di = f(i+1,j+1,n,triangle,dp) + triangle[i][j];
    return dp[i][j] =  min(d,di);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n,vector<int>(n,-1));
    return f(0,0,n-1,triangle,dp);
}