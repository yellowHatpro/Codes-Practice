#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int beautifulSubsets(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> subsets;
    int cnt = 0;
    function<void(int)> backtract = [&](int st) {
      for (int i = st; i < n; i++) {
        bool isBeautiful = true;
        for (int j : subsets) {
          if (abs(nums[i] - j) == k) {
            isBeautiful = false;
            break;
          }
        }
        if (isBeautiful) {
          subsets.push_back(nums[i]);
          ++cnt;
          backtract(i + 1);
          subsets.pop_back();
        }
      }
    };
    backtract(0);
    return cnt;
  }
};

class Solution2 {
public:
  int beautifulSubsets(vector<int> &nums, int k) {
    int n = nums.size();
    map<int, int> m;
    sort(nums.begin(), nums.end());
    function<int(vector<int>, int, int, map<int, int>)> f =
        [&](vector<int> nums, int i, int k, map<int, int> m) -> int {
      if (i == nums.size())
        return 1;
      int taken = 0;
      if (!m[nums[i] - k]) {
        m[nums[i]]++;
        taken = f(nums, i + 1, k, m);
        m[nums[i]]--;
      }
      int notTaken = f(nums, i + 1, k, m);
      return taken + notTaken;
    };
    return f(nums, 0, k, m) - 1;
  }
};
