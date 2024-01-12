#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool halvesAreAlike(string s) {
    set<char> count = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int j = s.size() / 2;
    int a = 0, b = 0;
    for (int i = 0; i < s.size() / 2; i++) {
      if (count.find(s[i]) != count.end()) {
        a++;
      }
      if (count.find(s[j + i]) != count.end()) {
        b++;
      }
    }
    return a == b;
  }
};
