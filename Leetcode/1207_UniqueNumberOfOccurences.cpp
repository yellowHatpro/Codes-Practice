#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    map<int, int> m;
    set<int> s;
    for (auto itr : arr) {
      m[itr]++;
    }
    for (auto [f, se] : m) {
      if (s.find(se) == s.end()) {
        s.insert(se);
      } else
        return false;
    }
    return true;
  }
};
