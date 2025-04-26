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

class SolutionPrefixSumWithHashmap {
public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    int count = 0;
    int currentSum = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
      currentSum += nums[i];
      if (m.find(currentSum - goal) != m.end()) {
        count += m[currentSum - goal];
      }
      m[currentSum]++;
    }
    return count;
  }
};
