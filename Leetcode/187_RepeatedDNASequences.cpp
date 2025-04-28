#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    if (s.length() < 10) {
      return {};
    }
    unordered_map<string, int> m;
    string seq = s.substr(0, 10);
    m[seq]++;
    for (int l = 0, r = 10; r < s.size(); r++) {
      seq += s[r];
      seq.erase(0, 1);
      l++;
      m[seq]++;
    }
    vector<string> res;
    for (auto &[a, b] : m) {
      if (a.length() == 10 and b > 1) {
        res.push_back(a);
      }
    }
    return res;
  }
};
