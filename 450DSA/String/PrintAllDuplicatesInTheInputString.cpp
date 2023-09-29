#include <bits/stdc++.h>
using namespace std;

vector<pair<char, int>> duplicate_char(string s, int n) {
  vector<pair<char, int>> res;
  vector<int> help(265);
  for (int i = 0; i < n; i++) {
    help[s[i]]++;
  }
  for (int i = 0; i < 265; i++) {
    if (help[i] > 1)
      res.push_back({(char)(i), help[i]});
  }
  return res;
}
