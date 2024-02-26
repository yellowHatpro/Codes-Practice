#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// 2 Pointer Solution
class Solution_2Pointer {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
      int j = i + 1;
      int k = n - 1;
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum < 0)
          j++;
        else if (sum > 0)
          k--;
        else {
          vector<int> v = {nums[i], nums[j], nums[k]};
          res.push_back(v);
          j++;
          k--;
          while (j < k && nums[j] == nums[j - 1])
            j++;
          while (j < k && nums[k] == nums[k + 1])
            k--;
        }
      }
    }
    return res;
  }
};

// Hashing Solution
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    set<vector<int>> s;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      set<int> hash;
      for (int j = i + 1; j < n; j++) {
        int target = -(nums[i] + nums[j]);
        if (hash.find(target) != hash.end()) {
          vector<int> v = {nums[i], nums[j], target};
          sort(v.begin(), v.end());
          s.insert(v);
        }
        hash.insert(nums[j]);
      }
    }
    vector<vector<int>> res = {s.begin(), s.end()};
    return res;
  }
};
