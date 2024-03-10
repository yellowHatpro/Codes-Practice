#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
    if (i > j)
      return 0;
    if (i == j) {
      int temp = nums[i];
      if (i - 1 >= 0)
        temp *= nums[i - 1];
      if (i + 1 < nums.size())
        temp *= nums[i + 1];
      return temp;
    }
    if (dp[i][j] != -1)
      return dp[i][j];
    int ans = 0;
    for (int k = i; k <= j; k++) {
      int temp = nums[k];
      if (j + 1 < nums.size())
        temp *= nums[j + 1];
      if (i - 1 >= 0)
        temp *= nums[i - 1];
      temp += f(i, k - 1, nums, dp) + f(k + 1, j, nums, dp);
      ans = max(ans, temp);
    }
    return dp[i][j] = ans;
  }

  int maxCoins(vector<int> &nums) {
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(1, n - 2, nums, dp);
  }
};
