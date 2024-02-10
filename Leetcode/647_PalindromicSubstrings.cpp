#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int isPalindrome(string s, int i, int j, vector<vector<int>> &dp) {
    if (dp[i][j] != -1) {
      return dp[i][j];
    }
    if (i >= j) {
      return 1;
    }
    return dp[i][j] = (s[i] == s[j]) ? isPalindrome(s, i + 1, j - 1, dp) : 0;
  }
  int countSubstrings(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (isPalindrome(s, i, j, dp)) {
          ans++;
        }
      }
    }
    return ans;
  }
};
