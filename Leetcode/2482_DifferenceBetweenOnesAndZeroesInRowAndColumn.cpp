#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid) {
    vector<pair<int, int>> r(grid.size(), pair<int, int>());
    vector<pair<int, int>> c(grid[0].size(), pair<int, int>());
    for (int i = 0; i < grid.size(); i++) {
      r[i] = {};
      r[i].first = 0;
      r[i].second = 0;
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 0) {
          r[i].first++;
        } else
          r[i].second++;
      }
    }
    for (int i = 0; i < grid[0].size(); i++) {
      c[i] = {};
      c[i].first = 0;
      c[i].second = 0;
      for (int j = 0; j < grid.size(); j++) {
        if (grid[j][i] == 0) {
          c[i].first++;
        } else
          c[i].second++;
      }
    }
    vector<vector<int>> res;
    for (auto x : r) {
      vector<int> row;
      for (auto y : c) {
        row.push_back(x.second + y.second - x.first - y.first);
      }
      res.push_back(row);
    }
    return res;
  }
};
