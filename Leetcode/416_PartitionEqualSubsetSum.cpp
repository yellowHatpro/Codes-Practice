#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool f(vector<vector<int>>&dp, vector<int>&nums, int sum, int i){
      if (sum==0) return true;  
      if (i==0){
        return nums[i] == sum;
    }
      if (dp[i][sum]!=-1) return dp[i][sum];
      int notTake = f(dp,nums,sum,i-1);
      int take = false;
      if (nums[i]<=sum){
        take = f(dp,nums,sum-nums[i],i-1);
    }
    return dp[i][sum]= take||notTake;
  }

    bool canPartition(vector<int>& nums) {
      int sum = accumulate(nums.begin(),nums.end(),0);
      if (sum%2) return false;
      sum/=2;
      vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
      return f(dp,nums,sum,nums.size()-1);
    }
};
