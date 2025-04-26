#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  long long f(int i, int x, int mult, int k, vector<int> &nums,
              vector<vector<long long>> &dp) {
    if (i == nums.size()) {
      return 0;
    }
    if (dp[i][mult + 1] != -1)
      return dp[i][mult + 1];
    long long newSub = 0;
    long long oldSub = 0;
    long long cnt = 0;
    // start new subarray here
    if (mult == -1) {
      if (nums[i] == x)
        cnt++;
      newSub = f(i + 1, x, -1, k, nums, dp);
      oldSub = cnt + f(i + 1, x, nums[i], k, nums, dp);
    } else {
      // continue with the previously continued subarray
      if ((mult * nums[i]) % k == x)
        cnt++;
      oldSub = cnt + f(i + 1, x, (mult * nums[i]) % k, k, nums, dp);
    }
    return dp[i][mult + 1] = newSub + oldSub;
  }

public:
  vector<long long> resultArray(vector<int> &nums, int k) {
    int n = nums.size();
    vector<long long> res;
    for (int i = 0; i < n; i++) {
      nums[i] %= k;
    }
    vector<vector<long long>> dp;
    for (int i = 0; i < k; i++) {
      dp.assign(n, vector<long long>(k + 1, -1));
      long long x_factor = f(0, i, -1, k, nums, dp);
      res.push_back(x_factor);
    }
    return res;
  }
};
