#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	int f(int idx, int prev, vector<vector<int>>&dp, vector<int>&nums){
		if (idx == nums.size()-1) return 0;
		if (dp[idx][prev+1]!=-1) return dp[idx][prev+1];
		int notTake = f(idx+1, prev, dp, nums);
		int take = 0;
		if (prev==-1 || nums[prev]<nums[idx]){
			take = 1 + f(idx+1, idx, dp, nums);
		}
		return dp[idx][prev+1]= max({take,notTake});
	}

    int lengthOfLIS(vector<int>& nums) {
    	int n = nums.size();
     	vector<vector<int>> dp(n, vector<int>(n+1,-1));
     	return f(0,-1,dp,nums);
    }
};