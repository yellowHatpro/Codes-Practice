#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for (auto itr : intervals) {
      if (itr[0] <= res.back()[1]) {
        res.back()[1] = max(itr[1], res.back()[1]);
      } else {
        res.push_back(itr);
      }
    }
    return res;
  }
};
