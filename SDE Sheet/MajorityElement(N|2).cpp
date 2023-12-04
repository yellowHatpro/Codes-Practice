#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int cnt = 1;
    int major = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (major != nums[i]) {
        cnt--;
      } else {
        cnt++;
      }
      if (cnt == 0) {
        major = nums[i];
        cnt = 1;
      }
    }
    return major;
  }
};
