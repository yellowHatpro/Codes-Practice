#include <bits/stdc++.h>
using namespace std;
int balancedBTsRecursive(int h) {
  if (h <= 1) {
    return 1;
  }
  int mod = (int)(pow(10, 9)) + 7;
  int x = balancedBTsRecursive(h - 1);
  int y = balancedBTsRecursive(h - 2);
  int temp1 = (x * x) % mod;
  int temp2 = (2 * x * y) % mod;
  int ans = (temp1 + temp2) % mod;
  return ans;
}

int balancedBTsDP(int n) {
  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return 3;
  }
  int mod = (int)(pow(10, 9)) + 7;
  int *dp = new int[n + 1];
  dp[1] = 1;
  dp[2] = 3;
  for (int i = 3; i <= n; i++) {
    dp[i] = -1;
  }
  for (int i = 3; i <= n; i++) {
    long x = long(dp[i - 1]);
    long y = long(dp[i - 2]);
    int temp1 = (int)(x * x) % mod;
    int temp2 = (int)(2 * x * y) % mod;
    int ans = (temp1 + temp2) % mod;
    dp[i] = ans;
  }
  return dp[n];
}
int main() {
  int h;
  cin >> h;
  cout << balancedBTsRecursive(h);
  cout << "DP Solution" << balancedBTsDP(h) << endl;
  return 0;
}
