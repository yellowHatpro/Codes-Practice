#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSubarrayLength(vector<int> &nums, int k) {
    int n = nums.size();
    map<int, int> m;
    int ans = 0;
    for (int l = 0, r = 0; r < n; r++) {
      m[nums[r]]++;
      while (m[nums[r]] > k) {
        m[nums[l++]]--;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
