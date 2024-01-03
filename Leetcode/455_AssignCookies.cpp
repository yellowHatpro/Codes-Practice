#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int n = g.size();
    int m = s.size();
    int i = 0;
    int j = 0;
    int ans = 0;
    while (i < n and j < m) {
      if (s[j] >= g[i]) {
        ans++;
        i++;
        j++;
      } else {
        j++;
      }
    }
    return ans;
  }
};
