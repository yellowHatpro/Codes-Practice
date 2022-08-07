#include <bits/stdc++.h>
using namespace std;
int main(){
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