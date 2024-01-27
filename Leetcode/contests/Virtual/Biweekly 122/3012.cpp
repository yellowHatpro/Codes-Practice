#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumArrayLength(vector<int> &nums) {
    int mini = *min_element(nums.begin(), nums.end());
    int cnt = 0;
    for (int i : nums) {
      if (i == mini)
        cnt++;
    }
    for (int i : nums) {
      if (i % mini)
        return 1;
    }
    return cnt + 1 / 2;
  }
};
