#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long maximumTripletValue(vector<int> &nums) {
    int n = nums.size();
    vector<int> imax(n);
    vector<int> kmax(n);
    imax[0] = nums[0];
    kmax[n - 1] = nums[n - 1];
    for (int i = 1; i < n - 1; i++) {
      imax[i] = max(imax[i - 1], nums[i - 1]);
      kmax[n - 1 - i] = max(imax[n - i], nums[n - i]);
    }
    long long ans = 0;
    for (int j = 1; j < n - 1; j++) {
      ans = max(ans, (long long)(imax[j] - nums[j]) * kmax[j]);
    }
    return ans;
  }
};
