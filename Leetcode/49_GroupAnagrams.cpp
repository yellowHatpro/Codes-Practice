#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    map<string, vector<string>> m;
    for (auto itr : strs) {
      string s = itr;
      sort(s.begin(), s.end());
      m[s].push_back(itr);
    }
    vector<vector<string>> res;
    for (auto [f, v] : m) {
      res.push_back(v);
    }
    return res;
  }
};
