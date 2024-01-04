#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums) {
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      m[nums[i]]++;
    }
    int ans = 0;
    for (auto [f, s] : m) {
      if (s == 1)
        return -1;
      if (s % 3 == 0 or (s - 2) % 3 == 0 or (s - 4) % 3 == 0) {
        if (s % 3 == 0) {
          ans += (s / 3);
        } else if ((s - 2) % 3 == 0) {
          ans += (s - 2) / 3;
          ans++;
        } else {
          ans += (s - 4) / 3;
          ans += 2;
        }
      } else if (s % 2 == 0) {
        ans += (s / 2);
      } else {
        return -1;
      }
    }
    return ans;
  }
};
