#include <bits/stdc++.h>

// Depending on where we put the nth element, we may add 0,1,...n-1 inverse
// pairs. Ex: we have permutation of 1..4, then:
// 5 x x x x creates 4 new inverse pairs
// x 5 x x x creates 3 new inverse pairs
// x x x x 5 creates 0 new inverse pairs
// dp[n][k] = dp[n-1][k-0] + dp[n-1][k-1] + ... + dp[n-1][k-(n-1)]
class Solution {
public:
  const int mod = 1e9 + 7;
  int dp[1001][1001];
  int f(int n, int k) {
    if (k <= 0)
      return k == 0;
    if (dp[n][k] != -1)
      return dp[n][k];
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += f(n - 1, k - i);
      ans %= mod;
    }
    return dp[n][k] = ans;
  }

  int kInversePairs(int n, int k) {
    // dp state will tell how many pairs till i index, with k pairs remaining
    memset(dp, -1, sizeof(dp));
    return f(n, k);
  }
};
