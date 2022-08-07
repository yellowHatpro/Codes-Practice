#include <bits/stdc++.h>
using namespace std;

//Problem equal to Subset Sum equal k, slight modification

bool f(int k, vector<int> &arr, int i, vector<vector<int>> &dp){
	if (k==0) return true;
	if(i==0) return arr[i] == k;
	if(dp[i][k]!=-1) return dp[i][k];
	bool notTake = f(k,arr,i-1,dp);
	bool take = false;
	if (arr[i]<=k){
		take = f(k-arr[i],arr,i-1,dp);
	}
	return dp[i][k] = take | notTake;
}

bool canPartition(vector<int> &arr, int n)
{
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		k+= arr[i];
	}
	if (k%2) return false;
	vector<vector<int>> dp(n,vector<int>(k+1,-1));
	return f(k/2,arr,n-1,dp);
}
