#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool find132pattern(vector<int> &nums) {
    stack<pair<int, int>>
        s; // monotonic decreasing stack containing Num and minBeforeNum
    int minTillTop =
        nums[0]; // minimum element till the top element of the stack
    for (int i : nums) {
      while (!s.empty() && s.top().first <= i) {
        s.pop();
      }
      if (!s.empty() && i < s.top().first && i > s.top().second)
        return true;
      s.push({i, minTillTop});
      minTillTop = min(minTillTop, i);
    }
    return false;
  }
};
