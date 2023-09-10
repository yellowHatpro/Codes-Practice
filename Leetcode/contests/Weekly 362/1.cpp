#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int numberOfPoints(vector<vector<int>> &nums) {
    map<int, int> m;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int st = nums[i][0];
      int lt = nums[i][1];
      for (int j = st; j <= lt; j++) {
        m[j] = 1;
      }
    }
    int ans = 0;
    for (int i = 0; i < m.size(); i++) {
      ans += m[i];
    }
    return ans;
  }
};
