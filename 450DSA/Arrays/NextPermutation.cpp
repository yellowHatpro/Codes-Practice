#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int low = -1, high;
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        low = i;
        break;
      }
    }
    if (low == -1) {
      reverse(nums.begin(), nums.end());
      return;
    }
    high = nums[low + 1];
    for (int i = low; i < n; i++) {
      if (nums[i] > nums[low]) {
        high = i;
      }
    }
    swap(nums[low], nums[high]);
    reverse(nums.begin() + low + 1, nums.end());
  }
};
