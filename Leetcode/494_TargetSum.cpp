#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	int f(vector<int>&nums, int target, vector<vector<int>>&dp,int i){
		if(i==0){
			if(nums[i]==0 && target==0) return 2;
			if(target==0 || nums[i]==target) return 1;
			else return 0;
		}
		if(dp[i][target]!=-1) return -1;
		int notTake = f(nums,target,dp,i-1);
		int take =0;
		if(nums[i]<=target){
			take = f(nums,target-nums[i],dp,i-1);
		}
		return take+notTake;
	}

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
        	totalSum+=nums[i];
        }
        int sum = (totalSum+target)/2;
        if(sum%2!=0) return 0;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return f(nums,sum,dp,nums.size()-1);
    }
};