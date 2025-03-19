#include <bits/stc++.h>
using namespace std;
class Solution {
public:
  int longestNiceSubarray(vector<int> &nums) {
    int curr = 0;
    int l = 0;
    int ans = 0;
    for (int r = 0; r < nums.size(); r++) {
      while ((curr & nums[r]) != 0) {
        curr ^= nums[l];
        l++;
      }
      ans = max(ans, r - l + 1);
      curr |= nums[r];
    }
    return ans;
  }
};
