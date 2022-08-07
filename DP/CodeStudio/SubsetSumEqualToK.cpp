#include <bits/stdc++.h>
using namespace std;

bool f(int i, int k , vector<int> &arr, vector<vector<int>> &dp){
	if(k==0) return true;
	if(i==0) return (arr[i]==k);
	if (dp[i][k]!=-1) return dp[i][k];
	bool notTake = f(i-1,k,arr,dp);
	//careful while taking "take"
	bool take = false;
	if(arr[i]<=k) take =  f(i-1,k-arr[i],arr,dp);
	return dp[i][k] = take or notTake;  
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
   vector<vector<int>> dp(n,vector<int>(k,-1));
    return f(n-1,k,arr,dp) or f(n-1,k-arr[n-1],arr,dp);
}