#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void f(vector<int> &nums, vector<vector<int>> &subsets, vector<int> subset,
         int i) {
    if (i == nums.size()) {
      subsets.push_back(subset);
      return;
    }
    subset.push_back(nums[i]);
    f(nums, subsets, subset, i + 1);
    subset.pop_back();
    f(nums, subsets, subset, i + 1);
  }
  int subsetXORSum(vector<int> &nums) {
    int sum = 0;
    vector<vector<int>> subsets;
    f(nums, subsets, {}, 0);
    for (auto subset : subsets) {
      int xorRes = 0;
      for (auto itr : subset) {
        xorRes ^= itr;
      }
      sum += xorRes;
    }
    return sum;
  }
};
