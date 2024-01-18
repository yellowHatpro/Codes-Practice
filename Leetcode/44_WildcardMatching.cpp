#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
    if (i < 0 or j < 0) {
      while (j >= 0 and p[j] == '*')
        j--;
      return i == j;
    }
    if (dp[i][j] != -1)
      return dp[i][j];
    if (s[i] == p[j] or p[j] == '?')
      return dp[i][j] = f(i - 1, j - 1, s, p, dp);
    else if (p[j] == '*') {
      return dp[i][j] = f(i - 1, j, s, p, dp) or f(i, j - 1, s, p, dp);
    }
    return dp[i][j] = false;
  }

  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, s, p, dp);
  }
};
