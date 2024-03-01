#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string maximumOddBinaryNumber(string s) {
    int lastOne = s.size() - 1;
    int it = s.size() - 1;
    while (it >= 0 and s[lastOne] != '1') {
      if (s[it] == '1') {
        swap(s[it], s[lastOne]);
      } else
        it--;
    }
    it = 0;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == '1') {
        swap(s[i], s[it]);
        it++;
      }
    }
    return s;
  }
};
