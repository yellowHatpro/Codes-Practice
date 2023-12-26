#include <bits/stdc++.h>
#include <numeric>
using namespace std;
class Solution {
public:
  int numSpecial(vector<vector<int>> &mat) {
    int cnt = 0;
    int n = mat.size();
    int m = mat[0].size();
    vector<int> vr = vector<int>(n);
    vector<int> vc = vector<int>(m);
    for (int i = 0; i < n; i++) {
      vr[i] += accumulate(mat[i].begin(), mat[i].end(), 0);
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        vc[i] += mat[j][i];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (vr[i] == 1 and vc[j] == 1 and mat[i][j] == 1) {
          cnt++;
        }
      }
    }
    return cnt;
  }
};
