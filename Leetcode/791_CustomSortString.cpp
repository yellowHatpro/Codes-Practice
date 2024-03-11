#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string customSortString(string order, string s) {
    string ans;
    map<char, int> m;
    for (auto itr : s) {
      m[itr]++;
    }
    for (auto itr : order) {
      if (m.find(itr) != m.end()) {
        while (m[itr] > 0) {
          ans += itr;
          m[itr]--;
        }
        if (m[itr] == 0)
          m.erase(itr);
      }
    }
    for (auto itr : m) {
      while (m[itr.first] > 0) {
        ans += itr.first;
        m[itr.first]--;
      }
    }
    return ans;
  }
};
