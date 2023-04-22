#include <bits/stdc++.h>
using namespace std;
int DP(){
	int n;cin>>n;
	vector<int> games(n);
	vector<int> dp(n);
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>games[i];
		sum+=games[i];
	}
	dp[0] = games[0];
	dp[1] = games[1];
	dp[2] = games[2];

	for (int i = 3; i < n; ++i)
	{
		dp[i] = min({dp[i-1],dp[i-2],dp[i-3]}) + games[i];
	}
	cout<<sum-min({dp[n-1],dp[n-2],dp[n-3]});
	return 0;
}

long long int f(int n, vector<long long int>&v, vector<long long int>&dp, int i){
	if (i>=n) return 0;
	if (dp[i]!=-1) return dp[i];
	long long int doubleTake = (i+1<n) ? v[i] + v[i+1] + f(n,v,dp,i+3) : 0;

	long long int take = max({v[i]+f(n,v,dp,i+2), doubleTake, f(n,v,dp,i+1) });
	return dp[i] = take;
}


int32_t main(){
	int n;cin>>n;
	vector<long long int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	vector<long long int> dp(n,-1);
	cout<<f(n,v,dp,0)<<endl;
}