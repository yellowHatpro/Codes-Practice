#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMaxK(vector<int> &nums) {
    map<int, bool> m;
    int ans = 0;
    for (auto num : nums) {
      int pos = abs(num);
      if (pos > ans and num < 0 and m[num]) {
        ans = pos;
      }

      if (num < 0)
        m[num] = 1;
    }
    return ans;
  }
};
