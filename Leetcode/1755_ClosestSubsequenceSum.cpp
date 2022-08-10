#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	bool f(vector<int> &nums, int target, vector<vector<int>>&dp,int i){
		if(target==0) return 1;
		if(i==0) return target==nums[i];
		if(dp[i][target]!=-1) return dp[i][target];
		int notTake = f(nums,target,dp,i-1);
		int take = false;
		if(nums[i]<=target) take = f(nums,target-nums[i],dp,i-1);
		return dp[i][target] =  take|notTake;
	}

    int minAbsDifference(vector<int>& nums, int goal) {
        int absSum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (nums[i]>0) absSum+=nums[i];
        }
        vector<vector<int>> dp(nums.size(),vector<int>(absSum+1,-1));
        int mini = 1e9;
        for (int i = 0; i <= absSum; ++i)
        {
        	if(f(nums,i,dp,nums.size()-1)){
        		mini = min(mini,abs(i-goal));
        	}
        }
        return mini;
    }
};