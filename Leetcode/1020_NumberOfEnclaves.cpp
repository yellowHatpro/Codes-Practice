#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  pair<bool, int> bfs(int i, int j, vector<vector<int>> &grid,
                      vector<vector<int>> &vis, int n, int m) {
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1;
    vector<int> dx{0, 1, 0, -1};
    vector<int> dy{-1, 0, 1, 0};
    int isNotCorner = true;
    int cnt = 0;
    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      cnt++;
      cout << isNotCorner << endl;
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int r = x + dx[i];
        int c = y + dy[i];
        if (r < 0 || r >= n || c < 0 || c >= m)
          isNotCorner = false;
        else if (grid[r][c] == 1 && !vis[r][c]) {
          q.push({r, c});
          vis[r][c] = 1;
        }
      }
    }
    cout << endl;
    return {isNotCorner, cnt};
  }

  int numEnclaves(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1 && !vis[i][j]) {
          pair<int, int> res = bfs(i, j, grid, vis, n, m);
          if (res.first) {
            cnt += res.second;
          }
        }
      }
    }
    return cnt;
  }
};
