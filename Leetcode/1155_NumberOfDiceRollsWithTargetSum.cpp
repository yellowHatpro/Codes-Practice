#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD (ll)1e9 + 7
class Solution {
public:
  ll f(int n, int k, int target, vector<vector<ll>> &dp) {
    if (target < 0)
      return 0;
    if (target == 0 && n != 0)
      return 0;
    if (target != 0 && n == 0)
      return 0;
    if (target == 0 && n == 0)
      return 1;
    ll ans = 0;
    if (dp[n][target] != -1)
      return dp[n][target];
    for (int i = 1; i <= k; ++i) {
      ans += f(n - 1, k, target - i, dp);
    }
    ans %= MOD;
    return dp[n][target] = ans;
  }

  int numRollsToTarget(int n, int k, int target) {
    vector<vector<ll>> dp(n + 1, vector<ll>(target + 1, -1));
    return f(n, k, target, dp);
  }
};
