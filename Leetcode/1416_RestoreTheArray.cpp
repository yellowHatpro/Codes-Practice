#include <bits/stdc++.h>
#define MOD 1e9+7
#define ll long long
using namespace std;
class Solution {
public:

	int f(string s, int k, vector<ll>&dp, int n, int i){
		if (i>=n) return 0;
		if (s[i]=='0') return 0;
		if (dp[i]!=-1) return dp[i];
		ll cnt = 0;
		ll num = 0;
		for (int j = i; j < n; ++j)
		{	
			num = num*10 + s[j];
			if (num>k){
				break;
			}
			cnt+=f(s,k,dp,n,j+1)%MOD;

		}
		return dp[i] = cnt;
	}

    int numberOfArrays(string s, int k) {
    	int n = s.size();
    	vector<ll> dp(n+1,-1);
        return f(s,k,dp,n,0);
    }
};