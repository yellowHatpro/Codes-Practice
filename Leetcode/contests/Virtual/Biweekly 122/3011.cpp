#include <bits/stdc++.h>
using namespace std;

// Simply use comparison based sorting algo, bubble or insertion and just add
// __builtin_popcount condition.

class Solution {
public:
  bool canSortArray(vector<int> &nums) {
    int n = nums.size();
    map<int, int> m;
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    for (auto itr : nums) {
      m[itr] = __builtin_popcount(itr);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - i - 1; j++) {
        if (nums[j + 1] < nums[j] and m[nums[j]] == m[nums[j + 1]]) {
          swap(nums[j + 1], nums[j]);
        }
      }
    }
    return nums == sorted;
  }
};
