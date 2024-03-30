#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int slidingWindowAtMost(vector<int> &nums, int distinctK) {
    map<int, int> m;
    int left = 0, cnt = 0;
    for (int right = 0; right < nums.size(); right++) {
      m[nums[right]]++;
      while (m.size() > distinctK) {
        m[nums[left]]--;
        if (m[nums[left]] == 0)
          m.erase(nums[left]);
        left++;
      }
      cnt += (right - left + 1);
    }
    return cnt;
  }
  int subarraysWithKDistinct(vector<int> &nums, int k) {
    return slidingWindowAtMost(nums, k) - slidingWindowAtMost(nums, k - 1);
  }
};
