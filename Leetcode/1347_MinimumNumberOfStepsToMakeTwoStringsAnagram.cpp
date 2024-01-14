#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minSteps(string s, string t) {
    map<char, int> m;
    int n = s.size();
    int ans = 0;
    for (auto itr : s) {
      m[itr]++;
    }
    for (auto itr : t) {
      if (m[itr] == 0) {
        ans++;
      } else {
        m[itr]--;
      }
    }
    return ans;
  }
};
