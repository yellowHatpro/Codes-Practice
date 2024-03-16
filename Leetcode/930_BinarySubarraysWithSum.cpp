#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    return slidingWindowAtMost(nums, goal) -
           slidingWindowAtMost(nums, goal - 1);
  }

private:
  int slidingWindowAtMost(vector<int> &nums, int goal) {
    int start = 0, currentSum = 0, totalCount = 0;
    for (int end = 0; end < nums.size(); end++) {
      currentSum += nums[end];
      while (start <= end && currentSum > goal) {
        currentSum -= nums[start++];
      }
      totalCount += end - start + 1;
    }
    return totalCount;
  }
};
