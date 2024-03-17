#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    int ans = 0, cnt = 0;
    unordered_map<int, int> mp;

    for (int idx = 1; idx <= nums.size(); idx++) {
      cnt += (nums[idx - 1] == 0 ? -1 : 1);

      if (cnt == 0 || mp.contains(cnt))
        ans = max(ans, idx - mp[cnt]);
      else
        mp[cnt] = idx;
    }

    return ans;
  }
};
