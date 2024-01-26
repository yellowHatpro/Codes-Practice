#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int mod = 1e9 + 7;
  int f(int i, int j, int maxMove, vector<vector<vector<int>>> &dp, int &m,
        int &n) {
    if (i < 0 or j < 0 or i >= m or j >= n)
      return 1;
    if (maxMove == 0)
      return 0;
    if (dp[i][j][maxMove] != -1)
      return dp[i][j][maxMove];
    int ans = 0;
    ans = (ans + f(i - 1, j, maxMove - 1, dp, m, n)) % mod;
    ans = (ans + f(i + 1, j, maxMove - 1, dp, m, n)) % mod;
    ans = (ans + f(i, j + 1, maxMove - 1, dp, m, n)) % mod;
    ans = (ans + f(i, j - 1, maxMove - 1, dp, m, n)) % mod;
    return dp[i][j][maxMove] = (ans) % mod;
  }

  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    vector<vector<vector<int>>> dp(
        m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, -1)));
    return f(startRow, startColumn, maxMove, dp, m, n);
  }
};
