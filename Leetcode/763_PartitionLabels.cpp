#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string s) {
    map<char, int> m;
    int n = s.length();
    vector<int> v(n, -1);
    m[s[0]] = 0;
    v[0] = 0;
    for (int i = 1; i < n; i++) {
      if (m.find(s[i]) == m.end()) {
        m[s[i]] = i;
        v[i] = v[i - 1] + 1;
      } else {
        int num = v[m[s[i]]];
        int j = i;
        int k = m[s[i]];
        for (int l = k; l <= j; l++) {
          v[l] = num;
        }
        m[s[i]] = i;
      }
    }
    vector<int> res(v[n - 1] + 1, 0);
    for (auto itr : v) {
      res[itr]++;
    }
    return res;
  }
};
