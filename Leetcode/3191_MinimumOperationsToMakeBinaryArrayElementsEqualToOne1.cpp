#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums) {
    int ans = 0;
    auto firstOccurenceOf0 = std::find(nums.begin(), nums.end(), 0);
    if (firstOccurenceOf0 == nums.end()) {
      return 0;
    } else {
      int index = std::distance(nums.begin(), firstOccurenceOf0);
      for (int i = index; i < nums.size(); i++) {
        if (nums[i] == 0) {
          if (i + 3 <= nums.size()) {
            for (int j = i; j < i + 3; j++) {

              nums[j] = 1 - nums[j];
            }
            ans++;
          }
        }
      }
    }
    auto it = std::find(nums.begin(), nums.end(), 0);
    if (it == nums.end()) {
      return ans;
    }
    return -1;
  }
};
