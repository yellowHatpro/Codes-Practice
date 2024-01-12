#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void f(vector<vector<int>> &res, vector<int> v, int k, int n, int index) {
    if (k == 0 and n == 0) {
      res.push_back(v);
      return;
    }
    if ((k == 0 and n != 0) or (k != 0 and n == 0)) {
      return;
    }
    for (int i = index; i <= 9; i++) {
      v.push_back(i);
      f(res, v, k - 1, n - i, i + 1);
      v.pop_back();
    }
  }

  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    f(res, {}, k, n, 1);
    return res;
  }
};
