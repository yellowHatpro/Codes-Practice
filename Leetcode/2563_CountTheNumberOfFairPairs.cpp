#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long custom_lower_bound(vector<int> &nums, int low, int high, int x) {
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] >= x) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }

  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
      auto l = custom_lower_bound(nums, i + 1, n - 1, lower - nums[i]);
      auto r = custom_lower_bound(nums, i + 1, n - 1, upper - nums[i] + 1);
      cnt += 1LL * (r - l);
    }
    return cnt;
  }
};
