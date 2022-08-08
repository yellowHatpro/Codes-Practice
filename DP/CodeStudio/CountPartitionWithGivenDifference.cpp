#include <bits/stdc++.h>
#define MOD int(1e9+7)
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
    return dp[i][k] = (take+notTake)% MOD;

}

int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0;
    for (int i = 0; i < n; ++i)
    {
    	totalSum+=arr[i];
    }
    int s1 = (totalSum+d)/2;
    if ( (totalSum+d)%2!=0) return 0;
    vector<vector<int>>dp(n,vector<int>(s1+1,-1));
    return f(n-1,s1,arr,dp);

}


