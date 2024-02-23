#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Function to return max value that can be put in knapsack of capacity W.

  int f(int *&wt, int *&val, int W, int i, vector<vector<int>> &dp) {
    if (i == 0) {
      if (wt[i] <= W) {
        return val[0];
      }
      return 0;
    }
    if (dp[i][W] != -1)
      return dp[i][W];
    int notTake = f(wt, val, W, i - 1, dp);
    int take = INT_MIN;
    if (wt[i] <= W) {
      take = val[i] + f(wt, val, W - wt[i], i - 1, dp);
    }
    return dp[i][W] = max(take, notTake);
  }

  int knapSack(int W, int wt[], int val[], int n) {
    // states: index, W
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return f(wt, val, W, n - 1, dp);
  }
};
