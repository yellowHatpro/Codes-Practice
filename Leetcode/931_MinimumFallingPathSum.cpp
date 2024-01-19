#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int f(int i, int j, vector<vector<int>> &vec, vector<vector<int>> &dp) {
    if (j < 0 or j >= vec[0].size())
      return 1e6;
    if (i == 0)
      return vec[i][j];
    if (dp[i][j] != INT_MIN)
      return dp[i][j];
    int c = vec[i][j] + f(i - 1, j, vec, dp);
    int l = vec[i][j] + f(i - 1, j - 1, vec, dp);
    int r = vec[i][j] + f(i - 1, j + 1, vec, dp);
    return dp[i][j] = min({l, r, c});
  }

  int minFallingPathSum(vector<vector<int>> &vec) {
    int n = vec.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
    int mini = INT_MAX;
    for (int i = 0; i < n; ++i) {
      mini = min(mini, f(n - 1, i, vec, dp));
    }
    return mini;
  }
};
