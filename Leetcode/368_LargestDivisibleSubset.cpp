#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> f(int ind, int prev, vector<int> &nums,
                vector<vector<vector<int>>> &dp) {
    if (ind == nums.size()) {
      return {};
    }

    if (dp[ind][prev + 1].size() != 0)
      return dp[ind][prev + 1];
    vector<int> take = {};
    if (prev == -1 || nums[ind] % nums[prev] == 0) {
      take = f(ind + 1, ind, nums, dp);
      take.insert(take.begin(), nums[ind]);
    }

    vector<int> nottake = f(ind + 1, prev, nums, dp);

    return dp[ind][prev + 1] = take.size() >= nottake.size() ? take : nottake;
  }

  vector<int> largestDivisibleSubset(vector<int> &nums) {
    vector<int> ans;
    int prev = -1;
    vector<vector<vector<int>>> dp(
        nums.size(), vector<vector<int>>(nums.size() + 1, vector<int>()));
    sort(nums.begin(), nums.end());
    return f(0, prev, nums, dp);
  }
};
