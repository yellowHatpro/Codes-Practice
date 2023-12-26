#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    int l = 0;
    long long largestSum = INT_MIN;
    long long runningSum = 0;
    for (int r = 0; r < nums.size(); r++) {
      runningSum += nums[r];
      if (r - l + 1 >= k) {
        runningSum -= nums[l];
        l++;
      }
      largestSum = max(runningSum, largestSum);
    }
    return (double)(largestSum / (double)k);
  }
};
