#include <bits/stdc++.h>
using namespace std;

int f(int idx, int k, vector<vector<int>> &arr, vector<vector<int>> &dp) {
  if (idx == arr.size() || k == 0)
    return 0;

  if (dp[idx][k] != -1)
    return dp[idx][k];

  vector<int> temp = {arr[idx][1] + 1, 0, 0};
  int j = lower_bound(arr.begin(), arr.end(), temp) - arr.begin();

  return dp[idx][k] =
             max(f(idx + 1, k, arr, dp), arr[idx][2] + f(j, k - 1, arr, dp));
}

int main() {
  int k;
  int n;
  cin >> k;
  cin >> n;
  vector<vector<int>> events(n, vector<int>(3, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> events[i][j];
    }
  }
  sort(events.begin(), events.end());
  vector<vector<int>> dp =
      vector<vector<int>>(events.size(), vector<int>(k + 1, -1));

  cout << f(0, k, events, dp) << endl;
  return 0;
}
