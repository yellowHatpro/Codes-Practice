#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int f(int n, int minProfit, vector<int>& group, vector<int>& profit, int g, int i, int cnt, int currProfit, vector<vector<vector<int>>>&dp){
		if (i==g){
			return currProfit>=minProfit;
		}
		if (dp[i][cnt][currProfit]!=-1) return dp[i][cnt][currProfit];
		int take = 0;
		if (cnt+group[i]<=n){
			take+=f(n,minProfit,group,profit,g,i+1,cnt+group[i],min(minProfit,currProfit+profit[i]),dp);
		}
		int notTake = f(n,minProfit,group,profit,g,i+1,cnt,currProfit,dp);
		return dp[i][cnt][currProfit] = (take+notTake)%(int)(1e9+7);
	}

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    	int g = profit.size();
    	//position count profit
    	vector<vector<vector<int>>> dp(101, vector<vector<int>>(101,vector<int>(101,-1)));
    	return f(n,minProfit,group,profit,g,0,0,0,dp);//idx, cnt, currProfit 
    }
};