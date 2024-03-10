#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minTaps(int n, vector<int> &ranges) {

    // Create a vector to store the minimum number of taps needed for each
    // position
    vector<int> dp(n + 1, 1e9);

    // Initialize the starting position of the garden
    dp[0] = 0;

    for (int i = 0; i <= n; i++) {
      // Calculate the leftmost position reachable by the current tap
      int tapStart = max(0, i - ranges[i]);
      // Calculate the rightmost position reachable by the current tap
      int tapEnd = min(n, i + ranges[i]);

      for (int j = tapStart; j <= tapEnd; j++) {
        // Update with the minimum number of taps
        dp[tapEnd] = min(dp[tapEnd], dp[j] + 1);
      }
    }

    // Check if the garden can be watered completely
    if (dp[n] == 1e9) {
      // Garden cannot be watered
      return -1;
    }

    // Return the minimum number of taps needed to water the entire garden
    return dp[n];
  }
};
