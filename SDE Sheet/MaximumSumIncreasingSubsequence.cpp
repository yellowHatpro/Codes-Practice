#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:

  int f(int*& arr,int n, int i, int prev, vector<vector<int>>&dp){
    if (i==n) return 0;
    if (dp[i][prev+1]!=-1) return dp[i][prev+1];
    int notTake = f(arr,n,i+1,prev,dp);
    int take = 0;
    if (prev==-1 || arr[prev]<arr[i]) take = arr[i] + f(arr,n,i+1,i,dp);
    return dp[i][prev+1] = max(take,notTake);
  }

	int maxSumIS(int arr[], int n)  
	{  
	  vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return f(arr,n,0,-1,dp);
	}  
};
