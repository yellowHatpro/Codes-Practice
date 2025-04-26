#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int res = 0;
    set<char> check;
    int l = 0;
    int r = 0;
    while (r < s.size()) {
      if (check.find(s[r]) == check.end()) {
        check.insert(s[r]);
        r++;
      } else {
        res = max(res, r - l);
        check.erase(s[l]);
        l++;
      }
    }
    res = max(res, r - l);
    return res;
  }
};

class SolutionSlidingWindowNew {
public:
  int lengthOfLongestSubstring(string s) {
    int res = 0;
    map<char, int> check;
    int l = 0;
    for (int r = 0; r < s.size(); r++) {
      check[s[r]]++;
      while (check[s[r]] > 1) {
        check[s[l++]]--;
      }
      res = max(res, r - l + 1);
    }
    return res;
  }
};

class SolutionWithLastBadIndex {
public:
  int lengthOfLongestSubstring(string s) {
    map<char, int> m;
    int l = 0;
    int res = 0;
    for (int r = 0; r < s.length(); r++) {
      if (m.find(s[r]) != m.end()) {
        l = max(l, m[s[r]] + 1);
      }
      m[s[r]] = r;
      res = max(res, r - l + 1);
    }
    return res;
  }
};
