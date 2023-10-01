#include <bits/stdc++.h>
using namespace std;
class SolutionBrute {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
    vector<int> result;
    vector<vector<int>> res(r, vector<int>(c));

    if ((r * c) != (mat.size() * mat[0].size()))
      return mat;

    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[i].size(); j++) {
        result.push_back(mat[i][j]);
      }
    }

    auto it = result.begin();
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        res[i][j] = *it;
        it++;
      }
    }
    return res;
  }
};
