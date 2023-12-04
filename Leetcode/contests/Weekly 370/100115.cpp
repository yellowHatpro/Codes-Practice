#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findChampion(vector<vector<int>> &grid) {
    int strong = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid.size(); j++) {
        if (i == j)
          continue;
        if (strong == j && grid[i][j] == 1)
          strong = i;
      }
    }
    return strong;
  }
};
