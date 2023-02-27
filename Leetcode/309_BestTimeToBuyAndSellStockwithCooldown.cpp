#include <bits/stdc++.h>
using namespace std;

//Buy Sell states: 1 -> Buy, 0-> Sell
//Map's key is pair denoting: <current day, state>

class Solution {
public:

    int f(vector<int>& prices, map<pair<int,int>, int> &dp, pair<int,int> state){
        if (state.first >= prices.size()) return 0;
        if (dp.count(state)) return dp[state];
        int _cooldown = f(prices,dp, {state.first+1, state.second});
        int _buy = INT_MIN;
        int _sell = INT_MIN;
        if (state.second==1){//buy state
            pair<int, int> newstate = {state.first+1, !state.second};
            _buy  = f(prices, dp, newstate) - prices[state.first];
        } else {// sell state
            pair<int, int> newstate = {state.first+2, !state.second};
            _sell = f(prices, dp, {state.first+2, !state.second}) + prices[state.first];
        }
        return dp[state] = max({_buy, _sell, _cooldown});
    }

    int maxProfit(vector<int>& prices) {
        map<pair<int, int>, int> dp;
        pair<int, int> initialState = {0,1};
        int n = prices.size()-1;
        f(prices, dp, initialState);
        for(auto itr: dp){
            cout<<itr.first.first<<" , "<<itr.first.second<<" : " << itr.second<<endl;
        }
        return max({dp[{0, 1}]});
    }
};