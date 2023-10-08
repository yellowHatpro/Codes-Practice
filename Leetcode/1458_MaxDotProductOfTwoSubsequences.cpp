#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int f(vector<int> &nums1, vector<int> &nums2, int i, int j, int sum, int n,
        int m, vector<vector<int>> &dp) {
    if (i >= n || j >= m) {
      return 0;
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }
    int choice1 =
        nums1[i] * nums2[j] + f(nums1, nums2, i + 1, j + 1, sum, n, m, dp);
    int choice2 = f(nums1, nums2, i + 1, j, sum, n, m, dp);
    int choice3 = f(nums1, nums2, i, j + 1, sum, n, m, dp);
    return dp[i][j] = max({choice1, choice2, choice3});
  }

  int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
    // states: i,j
    int n = nums1.size();
    int m = nums2.size();
    int firstMax = INT_MIN;
    int secondMax = INT_MIN;
    int firstMin = INT_MAX;
    int secondMin = INT_MAX;

    for (int num : nums1) {
      firstMax = max(firstMax, num);
      firstMin = min(firstMin, num);
    }
    for (int num : nums2) {
      secondMax = max(secondMax, num);
      secondMin = min(secondMin, num);
    }

    // Check special cases where all elements are negative
    if ((firstMax < 0 && secondMin > 0) || (firstMin > 0 && secondMax < 0)) {
      return max(firstMax * secondMin, firstMin * secondMax);
    }

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(nums1, nums2, 0, 0, 0, n, m, dp);
  }
};
