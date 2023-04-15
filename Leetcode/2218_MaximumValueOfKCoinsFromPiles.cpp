#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	int f(vector<vector<int>>& piles, int i, int k, vector<vector<int>>& dp){
		if (i<0 || k<0) return 0;
		if (dp[i][k]!=-1) return dp[i][k];
		int notTake = f(piles, i-1,k,dp);
		int take = INT_MIN;
		int sz = piles[i].size();
		int s = min(k,sz);
		int sum = 0;
		for (int j = 0; j < s; ++j)
		{	
			sum+=piles[i][j];
			take = max(take, sum + f(piles, i-1, k-j-1, dp));
		}
		return dp[i][k]=max(take,notTake);
	}

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return f(piles,n-1,k,dp);
    }
};