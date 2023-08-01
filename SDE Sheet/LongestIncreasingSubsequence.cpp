#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int f(vector<int>&nums, vector<vector<int>>&dp, int n, int idx, int prev){
      if (idx==n) return 0;
      if (dp[idx][prev+1]!=-1) return dp[idx][prev+1];
      int notTake = 0 + f(nums,dp,n,idx+1,prev);
      int take = INT_MIN;
      if (prev==-1 || nums[prev]<nums[idx]){
        take = 1 + f(nums,dp,n,idx+1,idx);
    }
    return dp[idx][prev+1] = max(take,notTake);
  }

    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      vector<vector<int>> dp(n,vector<int>(n+1,-1));
      return f(nums,dp,n,0,-1);
    }
};
