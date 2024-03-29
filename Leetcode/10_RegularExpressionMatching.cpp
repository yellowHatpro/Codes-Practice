#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
    if (i < 0 and j < 0)
      return true;
    if (i < 0) {
      if (p[j] == '*')
        return f(i, j - 2, s, p, dp);
      else
        return false;
    }
    if (j < 0)
      return false;
    if (dp[i][j] != -1)
      return dp[i][j];
    if (s[i] == p[j] or p[j] == '.') {
      return dp[i][j] = f(i - 1, j - 1, s, p, dp);
    } else if (p[j] == '*') {
      bool a = f(i, j - 2, s, p, dp);
      bool b = (s[i] == p[j - 1] or p[j - 1] == '.') and f(i - 1, j, s, p, dp);
      return dp[i][j] = a or b;
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
