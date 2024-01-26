#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> countOfPairs(int n, int x, int y) {
    vector<int> ans(n);
    map<pair<int, int>, int> m;
    if (x > y) {
      swap(x, y);
    }
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {

        int k = (min(j - i, abs(i - x) + 1 + abs(j - y)));
        ans[k - 1] += 2;
      }
    }

    return ans;
  }
  vector<int> countOfPairsFloydWarshall(int n, int x, int y) {
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 1000));
    for (int i = 1; i < n; i++) {
      grid[i][i + 1] = 1;
      grid[i + 1][i] = 1;
    }
    grid[x][y] = 1;
    grid[y][x] = 1;
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
        }
      }
    }
    vector<int> ans(n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i != j) {
          int val = grid[i][j];
          ans[val - 1]++;
        }
      }
    }
    return ans;
  }
};
