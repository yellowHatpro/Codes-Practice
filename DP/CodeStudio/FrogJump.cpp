#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int> &heights, vector<int> &dp) {
  int b = INT_MAX;
  if (n == 0)
    return 0;
  if (dp[n] != -1)
    return dp[n];
  int a = f(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
  if (n > 1)
    b = f(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
  int res = min(a, b);
  return dp[n] = res;
}

int frogJump(int n, vector<int> &heights) {
  vector<int> dp(n + 1, -1);
  return f(n - 1, heights, dp);
}

int frogJumpDP(int n, vector<int> &heights) {
  vector<int> dp(n, 0);
  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    int fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);
    int ss = INT_MAX;
    if (i > 1)
      ss = dp[i - 2] + abs(heights[i] - heights[i - 2]);
    dp[i] = min(fs, ss);
  }
  return dp[n - 1];
}
