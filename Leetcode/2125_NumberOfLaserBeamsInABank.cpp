#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numberOfBeams(vector<string> &bank) {
    vector<int> v;
    int n = bank.size();
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < bank[i].size(); j++) {
        if (bank[i][j] == '1')
          cnt++;
      }
      if (cnt != 0)
        v.push_back(cnt);
    }
    int ans = 0;
    for (int i = 1; i < v.size(); i++) {
      ans += (v[i - 1] * v[i]);
    }
    return ans;
  }
};
