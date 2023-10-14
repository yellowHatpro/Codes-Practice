#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    res.push_back({intervals[0][0], intervals[0][1]});
    for (auto itr : intervals) {
      int f = itr[0];
      int s = itr[1];
      if (res.back()[1] >= itr[1])
        continue;
      if (res.back()[1] >= itr[0])
        res.back()[1] = itr[1];
      else
        res.push_back(itr);
    }
    return res;
  }
};
