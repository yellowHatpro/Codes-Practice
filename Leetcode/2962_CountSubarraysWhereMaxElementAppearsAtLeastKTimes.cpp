#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    int ele = *max_element(nums.begin(), nums.end());
    long long ans = 0, st = 0;
    for (int en = 0; en < nums.size(); en++) {
      if (nums[en] == ele) {
        k--;
      }
      while (!k) {
        if (nums[st] == ele) {
          k++;
        }
        st++;
      }
      ans += st;
    }
    return ans;
  }
};
