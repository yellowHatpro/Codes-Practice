#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    map<string, int> mp;
    for (auto itr : matrix) {
      string s(itr.size(), 'T');
      for (int i = 1; i < itr.size(); i++) {
        if (itr[i] != itr[0])
          s[i] = 'F';
      }
      mp[s]++;
    }
    int ans = 0;
    for (auto itr : mp) {
      ans = max(ans, itr.second);
    }
    return ans;
  }
};
