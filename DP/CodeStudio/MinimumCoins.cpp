#include <bits/stdc++.h>
using namespace std;

int f(int i,int x,vector<int> &num,vector<vector<int>> &dp){
	if (i==0){
		if (x%num[i]==0) return x/num[i];
		return 1e9;
	}
	if (dp[i][x]!=-1) return dp[i][x];
	int notTake = f(i-1,x,num,dp);
	int take = 1e9;
	if(num[i]<=x) {
		take = f(i,x-num[i],num,dp) + 1;//if infinite supply of coins or whatever just dont iterate to lower index
	}
	return dp[i][x]= min(take,notTake);
}

int minimumElements(vector<int> &num, int x)
{	int n = num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,-1));
    return (f(n-1,x,num,dp)>=1e9) ? -1: f(n-1,x,num,dp);
}