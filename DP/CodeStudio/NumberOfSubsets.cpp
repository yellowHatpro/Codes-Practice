#include <bits/stdc++.h>
using namespace std;

int f(int i, int k, vector<int> &num, vector<vector<int>> &dp){
    if (i==0) {
        if (num[i]==0 && k==0) return 2;
        if (k==0 || num[i]==k) return 1;
        else return 0;
    }
    if (dp[i][k]!=-1) return dp[i][k];
    int notTake = f(i-1,k,num,dp);
    int take = 0;
    if(num[i]<=k){
        take = f(i-1,k-num[i],num,dp);
    }
    return dp[i][k] = take+notTake;

}

int findWays(vector<int> &num, int tar)
{    int n = num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    return f(n-1,tar,num,dp);
}