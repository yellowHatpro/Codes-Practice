#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
	//Take, Not take is not the only case here
	int f(ll currentCoin, int amount, vector<int>&dp, vector<int>& coins){
		ll ans = 0;
		if (currentCoin==amount) return 1;
		if (currentCoin>amount) return 0;
		if (dp[currentCoin]!=-1) return dp[currentCoin];
		for(ll itr: coins){

			if (currentCoin+itr<=amount){ll res = f(currentCoin+itr, amount, dp, coins);
						ans+= res;}
		}
		return dp[currentCoin] = ans;
	}

    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,-1);
        return f(0, amount, dp, coins);
    }
};