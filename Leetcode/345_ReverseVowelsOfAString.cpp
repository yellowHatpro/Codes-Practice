#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string reverseVowels(string s) {
    int i = 0;
    int j = s.size();
    set<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    while (i <= j) {
      if (v.find(s[i]) != v.end() and v.find(s[j]) != v.end()) {
        swap(s[i], s[j]);
        i++;
        j--;
      } else if (v.find(s[i]) == v.end())
        i++;
      else
        j--;
    }
    return s;
  }
};
