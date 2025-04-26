#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximumPossibleSize(vector<int> &nums) {
    int maxTillNow = 0;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= maxTillNow) {
        maxTillNow = nums[i];
        cout << maxTillNow << endl;
      } else {
        cnt++;
      }
    }
    return nums.size() - cnt;
  }
};
