
//States: 0 -> Buy, 1 -> Sell

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	int f(map<pair<int,int>,int> &dp, int fee, vector<int>& prices, pair<int,int> state){
		int currState = state.second;
		int currDay = state.first;
		if (currDay>=prices.size()) return 0;
		if (dp.count(state)){
			return dp[state];
		}
		int _buy = INT_MIN;
		int _sell = INT_MIN;
		int _nothing = f(dp, fee, prices, {currDay+1,currState});
		if (currState == 0){
			//buy
			_buy = f(dp, fee, prices, {currDay+1,!currState}) - prices[currDay];
		}
		else {
			_sell = f(dp, fee, prices, {currDay+1, !currState}) - fee + prices[currDay];
		}
		return dp[state] = max({_nothing, _sell, _buy});
	}

    int maxProfit(vector<int>& prices, int fee) {
  		     map<pair<int,int>, int> dp;
  		     f(dp,fee, prices, {0,0});
  		     return dp[{0,0}];
    }
};