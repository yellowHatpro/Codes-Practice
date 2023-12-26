#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    int n = min(str1.size(), str2.size());
    int m = max(str1.size(), str2.size());
    int i = 0;
    for (; i < n; i++) {
      if (str1[i] != str2[i]) {
        break;
      }
    }
    if (i == 0)
      return "";
    string res = "";

    int gcd1 = __gcd(i, n);
    int gcd2 = __gcd(i, m);
    int gcd = __gcd(gcd1, gcd2);
    for (int j = 0; j < gcd; j++) {
      res += str1[j];
    }
    string ss = "";
    string sa = "";
    for (int j = 0; j < m / gcd; j++) {
      ss += res;
    }
    for (int j = 0; j < n / gcd; j++) {
      sa += res;
    }
    if (str1.size() > str2.size()) {
      if (str1 == ss and str2 == sa)
        return res;
      else
        return "";
    } else {
      if (str1 == sa and str2 == ss)
        return res;
      else
        return "";
    }
  }
};
