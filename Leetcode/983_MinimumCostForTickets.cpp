#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,-1);
        return f(days,costs,dp,0);
    }
    int f(vector<int>&days, vector<int>&costs, vector<int>&dp, int i){
    	if (i==days.size()) return 0;
    	if (dp[i]!=-1) return dp[i];
    	int a = costs[0] + f(days,costs,dp, newi(i,days,1));
    	int b = costs[1] + f(days,costs,dp, newi(i,days,7));
    	int c = costs[2] + f(days,costs,dp, newi(i,days,30));
    	return dp[i] = min({a,b,c});
    }
    int newi(int i, vector<int>&days, int cost){
    	int x = days[i] + cost;
    	return  lower_bound(days.begin(), days.end(), x) - days.begin() ;
    }
};