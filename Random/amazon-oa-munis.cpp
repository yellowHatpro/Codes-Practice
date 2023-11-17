#include <bits/stdc++.h>
using namespace std;

int findFirstUnique(string s) {
  map<char, int> m;
  for (auto ch : s) {
    m[ch] += 1;
  }
  for (int i = 0; i < s.size(); i++) {
    if (m[i] == 1) {
      return i + 1;
    }
  }
  return -1;
}
