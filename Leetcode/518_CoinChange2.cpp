#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
	//Take, Not take is not the only case here
	int f(int i, int amount, vector<vector<int>>&dp, vector<int>& coins){
		if (i==0){
			return (amount%coins[0]);
		}
		if (dp[i][amount]!=-1){
			return dp[i][amount];
		}
		long long int notTaken = f(i-1,amount,dp,coins);
		long long int taken = 0;
		if (coins[i]<=amount){
			taken = f(i,amount-coins[i],dp,coins);
		}
		return dp[i][amount] = taken+notTaken;
	}

    int change(int amount, vector<int>& coins) {
		vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return f(coins.size()-1, amount, dp, coins);
    }
};