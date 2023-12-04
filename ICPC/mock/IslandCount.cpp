#include <bits/stdc++.h>
using namespace std;
class IslandCount {
public:
  // DO NOT read from stdin or write to stdout.
  // Input is given as the function arguments.
  // Output is taken as the function return value.

  vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                             {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  void travel(vector<string> &grid, vector<vector<int>> &vis, int i, int j,
              int n, int m) {
    vis[i][j] = 1;
    queue<vector<int>> q;
    q.push({i, j});
    while (!q.empty()) {
      int row = q.front()[0];
      int col = q.front()[1];
      q.pop();
      for (int x = 0; x < 8; x++) {
        int r = row + dir[x][0];
        int c = col + dir[x][1];
        if (r >= 0 and c >= 0 and r < n and c < m and grid[r][c] == '1' and
            !vis[r][c]) {
          vis[r][c] = 1;
          q.push({r, c});
        }
      }
    }
  }

  int getCount(vector<string> grid) {
    if (grid.size() == 0)
      return 0;
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '1' and !visited[i][j]) {
          cnt++;
          travel(grid, visited, i, j, n, m);
        }
      }
    }
    return cnt;
  }
};
