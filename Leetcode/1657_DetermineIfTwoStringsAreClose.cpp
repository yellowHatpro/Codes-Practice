#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool closeStrings(string word1, string word2) {
    map<char, int> m1;
    map<char, int> m2;
    multiset<int> s;
    for (auto itr : word1) {
      m1[itr]++;
    }
    for (auto itr : word2) {
      m2[itr]++;
    }
    if (m1.size() != m2.size())
      return false;
    for (auto itr : m1) {
      s.insert(itr.second);
    }
    for (auto itr : m2) {
      if (m1.find(itr.first) == m1.end())
        return false;
    }
    for (auto itr : m2) {
      if (s.find(itr.second) == s.end())
        return false;
      else
        s.erase(s.find(itr.second));
    }
    return s.size() == 0;
  }
};
