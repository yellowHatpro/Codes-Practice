#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>> &vec, vector<vector<int>>&dp){
    if (j<0 || j>=vec[0].size()) return 1e8;
    if (i==0) return vec[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int l = vec[i][j] + f(i-1,j-1,vec,dp);
    int r = vec[i][j] + f(i-1,j+1,vec,dp);
    int c = vec[i][j] + f(i-1,j,vec,dp);
    return dp[i][j] = min({l,r,c});
}

int minFallingPathSum(vector<vector<int>> &vec, int n) {
    vector<vector<int>> dp(n, vector<int>(n,-1));
    int mini = 1e8;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, f(n-1,i,vec,dp));
    }
    return mini;
}