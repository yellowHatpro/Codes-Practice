#include <bits/stdc++.h>
using namespace std;


bool f(vector<int>&arr,int i,vector<vector<int>> &dp, int sum){
	if(sum==0) return true;
	if(i==0) return (arr[i]==sum);
	if(dp[i][sum]!=-1) return dp[i][sum];
	int notTake = f(arr,i-1,dp,sum);
	int take = false;
	if(arr[i]<=sum) take = f(arr,i-1,dp,sum-arr[i]);
	return dp[i][sum] = take | notTake;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalSum = 0;
	for (int i = 0; i < n; ++i)
	{
		totalSum+=arr[i];
	}
	vector<vector<int>> dp(n, vector<int>(totalSum+1,-1));


	int mini = 1e9;

	for (int i = 0; i <= totalSum; ++i)
	{
		if (f(arr,n-1,dp,i)) {
			mini = min(mini,abs(totalSum-i-i));
		}	
	}
	return mini;
}