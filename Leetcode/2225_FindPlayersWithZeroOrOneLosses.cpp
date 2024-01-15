#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    map<int, vector<int>> loses;
    for (auto itr : matches) {
      loses[itr[1]].push_back(itr[0]);
      if (loses[itr[0]].size() == 0) {
        loses[itr[0]] = {};
      }
    }
    vector<vector<int>> res(2);
    for (auto itr : loses) {
      if (itr.second.size() == 0) {
        res[0].push_back(itr.first);
      } else if (itr.second.size() == 1) {
        res[1].push_back(itr.first);
      }
    }
    return res;
  }
};
