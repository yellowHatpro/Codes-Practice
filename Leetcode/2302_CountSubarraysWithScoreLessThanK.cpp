#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long countSubarrays(vector<int> &nums, long long k) {
    int n = nums.size();
    long long cnt = 0;
    long long totalSum = 0;
    for (int l = 0, r = 0; r < n; r++) {
      totalSum += nums[r];
      while (totalSum * (r - l + 1) >= k) {
        totalSum -= nums[l];
        l++;
      }
      cnt += r - l + 1;
    }
    return cnt;
  }
};
