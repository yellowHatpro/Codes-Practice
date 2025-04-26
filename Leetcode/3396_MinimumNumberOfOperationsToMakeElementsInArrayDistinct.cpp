#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    unordered_map<int, int> m;
    int n = nums.size();
    int cursedIndex = -1;
    for (int i = 0; i < n; i++) {
      if (m.find(nums[i]) != m.end()) {
        cursedIndex = max(cursedIndex, m[nums[i]]);
        m.erase(nums[i]);
      }
      m[nums[i]] = i;
    }
    if (cursedIndex == -1)
      return 0;
    return floor(cursedIndex / 3) + 1;
  }
};
