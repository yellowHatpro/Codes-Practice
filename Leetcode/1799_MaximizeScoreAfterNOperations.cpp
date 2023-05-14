#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	int f(const vector<int>& nums, int round, int state, unordered_map<int,int> &dp) {
		if (round>nums.size()/2) return 0;
		if (dp[state]>0) return dp[state];
		int ans = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = i+1; j < nums.size(); ++j)
			{
				int mask = (1<<i) | (1<<j); //mask tells if the 2 indices have been picked or not
				if ((mask&state)==0) {
					//if not picked
					ans=max(ans, round*__gcd(nums[i],nums[j]) + f(nums,round+1,state|mask,dp));
				}
			}
		}
		return dp[state] = ans;
	}

    int maxScore(vector<int>& nums) {
        unordered_map<int,int> dp;
        return f(nums, 1, 0, dp);
    }
};