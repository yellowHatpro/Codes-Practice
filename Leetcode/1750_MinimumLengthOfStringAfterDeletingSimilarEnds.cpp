#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumLength(string s) {
    int l = 0;
    int r = s.size() - 1;
    while (l < r and s[l] == s[r]) {
      char ch = s[l];
      while (l <= r and s[l] == ch) {
        l++;
      }
      while (l < r and s[r] == ch) {
        r--;
      }
    }
    return r - l + 1;
  }
};
