#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isAnagram(string s, string t) {
    map<char, int> m;
    for (int i = 0; i < s.length(); ++i) {
      m[s[i]]++;
    }
    for (int i = 0; i < t.length(); ++i) {
      if (m[t[i]] == 0) {
        return false;
      } else if (m[t[i]] == 1) {
        m.erase(t[i]);
      } else {
        m[t[i]]--;
      }
    }
    return m.size() == 0;
  }
};

class SolutionSort {
public:
  bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t)
      return true;
    else
      return false;
  }
};
