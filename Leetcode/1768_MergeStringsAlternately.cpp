#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    int n = min(word1.size(), word2.size());
    int i = 0;
    string res = "";
    for (; i < n; i++) {
      res += word1[i];
      res += word2[i];
    }
    if (i >= word1.size()) {
      for (; i < word2.size(); i++) {
        res += word2[i];
      }
    }
    if (i >= word2.size()) {
      for (; i < word1.size(); i++) {
        res += word1[i];
      }
    }
    return res;
  }
};
