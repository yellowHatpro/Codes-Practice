#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool f(int i, int j, string s, string p, vector<vector<int>> &dp) {
    if (i >= s.size() and j >= p.size())
      return true;
    if (i < s.size() and j >= p.size())
      return false;
    if (dp[i][j] != -1)
      return dp[i][j];
    bool match = (i < s.size() and (s[i] == p[j] or p[j] == '.'));
    if (j + 1 < p.size() and p[j + 1] == '*') {
      return dp[i][j] =
                 (match and f(i + 1, j, s, p, dp)) or f(i, j + 2, s, p, dp);
    }
    if (match) {
      return dp[i][j] = f(i + 1, j + 1, s, p, dp);
    }
    return dp[i][j] = false;
  }

  bool isMatch(string s, string p) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
    return f(0, 0, s, p, dp);
  }
};
