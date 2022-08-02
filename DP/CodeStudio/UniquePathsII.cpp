#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if (i==0 && j==0) return 1;
    if (i<0 || j<0||mat[i][j]==-1) return 0;
    if (dp[i][j]!=-1) return dp[i][j];
    int a = f(i-1,j,mat,dp);
    int b = f(i,j-1,mat,dp);
    return dp[i][j] = (a+b)%MOD;
}  

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,mat,dp);
}