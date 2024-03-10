#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int f(int i, int j, int *&arr, vector<vector<int>> &dp) {
    if (i == j)
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    int mini = INT_MAX;
    for (int k = i; k < j; k++) {
      int steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr, dp) +
                  f(k + 1, j, arr, dp);
      mini = min(steps, mini);
    }
    return dp[i][j] = mini;
  }

  int matrixMultiplication(int N, int arr[]) {
    int i = 1;
    int j = N - 1;
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return f(i, j, arr, dp);
  }
};
