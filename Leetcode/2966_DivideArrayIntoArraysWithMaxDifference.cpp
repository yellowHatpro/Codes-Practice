#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> divideArray(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n / 3; i++) {
      vector<int> v;
      v.push_back(nums[3 * i]);
      for (int j = 1; j < 3; j++) {
        if (nums[3 * i + j] - v[0] > k)
          return {};
        v.push_back(nums[3 * i + j]);
      }
      ans.push_back(v);
    }
    return ans;
  }
};
