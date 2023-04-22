#include <bits/stdc++.h>
using namespace std;


void DP(int n, vector<int>& minutes){
	
	vector<int> dp(n);
	dp[0] = minutes[0];
	dp[1] = minutes[1];
	dp[2] = minutes[2];
	for (int i = 3; i < n; ++i)
	{
		dp[i] = min({dp[i-1],dp[i-2],dp[i-3]}) + minutes[i];
	}
	cout<< min({dp[n-1],dp[n-2],dp[n-3]});
}

int memo(int n, vector<int>& mint, int i,vector<int>&dp){
	if (i>=n){
		return 0;
	}
	if (dp[i]!=-1) return dp[i];
	int take = mint[i] + min({memo(n,mint,i+1,dp),memo(n,mint,i+2,dp),memo(n,mint,i+3,dp)});
	return dp[i] = take;
}

int main() {
	int n;cin>>n;
	vector<int> minutes;
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		minutes.push_back(x);
	}
	vector<int> dp(n,-1);
	cout<<min({memo(n,minutes,0,dp),memo(n,minutes,1,dp),memo(n,minutes,2,dp)})<<endl;
	return 0;
}
