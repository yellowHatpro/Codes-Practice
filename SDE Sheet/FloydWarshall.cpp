#include <bits/stdc++.h>
using namespace std;

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
  vector<vector<int>> mat(n, vector<int>(n, 1000000000));
  for (auto edge : edges) {
    mat[edge[0] - 1][edge[1] - 1] = edge[2];
  }
  for (int i = 0; i < n; i++) {
    mat[i][i] = 0;
  }
  for (int via = 0; via < n; via++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][via] != 1000000000 && mat[via][j] != 1000000000)
          mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
      }
    }
  }
  return mat[src - 1][dest - 1];
}
