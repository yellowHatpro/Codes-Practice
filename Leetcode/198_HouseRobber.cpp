#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int f(vector<int> &nums, int i, vector<int> &dp) {
    if (i == 0)
      return nums[0];
    if (i < 0)
      return 0;
    if (dp[i] != -1)
      return dp[i];
    int take = f(nums, i - 2, dp) + nums[i];
    int notTake = f(nums, i - 1, dp);
    return dp[i] = max(take, notTake);
  }

  int rob(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return f(nums, n - 1, dp);
  }
};
class SolutionDP {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (nums.size() == 1)
      return nums[0];
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
      dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }
    return dp[n - 1];
  }
};
