#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &nums) {
  int n = nums.size() + 2;
  vector<vector<int>> dp(n, vector<int>(n));
  vector<int> new_nums(n, 1);
  int i = 1;
  for (auto num : nums) {
    new_nums[i++] = num;
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 0; i <= n - len; i++) {
      int j = i + len - 1;
      for (int k = i + 1; k < j; k++) {
        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] +
                                     new_nums[i] * new_nums[k] * new_nums[j]);
      }
    }
  }
  return dp[0][n - 1];
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int ans = f(v);
  cout << ans << endl;
  return 0;
}
