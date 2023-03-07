#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
	//Take, Not take is not the only case here
	int f(ll currentCoin, int amount, vector<int>&dp, vector<int>& coins){
		ll ans = INT_MAX;
		if (currentCoin==amount) return 0;
		if (currentCoin>amount) return -1;
		if (dp[currentCoin]!=0) return dp[currentCoin];
		for(ll itr: coins){
			ll res = f(currentCoin+itr, amount, dp, coins);
			if (res>=0 && res<ans) ans = 1 + res; // This part : NOTE to future self: dont just write ans = min(ans, f(...)) here, check first if current result is lesser than ans, then put ans = res +1 .. +1 is imp...
		}
		return dp[currentCoin] = ans==INT_MAX ? -1 : ans;
	}

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,0);
        int ans = INT_MAX;
        return f(0, amount, dp, coins);
    }
};