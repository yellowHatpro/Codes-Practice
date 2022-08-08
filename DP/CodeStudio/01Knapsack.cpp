#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &weight,vector<int>&value, int i, int maxWeight, vector<vector<int>> &dp){
	if (i==0){
		if (weight[i]<=maxWeight) return value[i];
		return 0;
	}
	if(dp[i][maxWeight]!=-1) return dp[i][maxWeight];
	int notTake = f(weight,value,i-1,maxWeight,dp);
	int take = INT_MIN;
	if (weight[i]<=maxWeight) {
		take = f(weight,value,i-1,maxWeight-weight[i],dp) + value[i];
	}
	return dp[i][maxWeight] = max(take,notTake);

}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return f(weight,value,n-1,maxWeight,dp);
}