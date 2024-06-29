#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<string> result;
  void f(int idx, string currAns, string s, set<string> ans) {
    if (idx == s.size()) {
      result.push_back(currAns);
      currAns.clear();
    }
    for (int i = idx; i < s.size(); i++) {
    }
  }

  vector<string> wordBreak(string s, vector<string> &wordDict) {
    string currentAns = "";
    set<string> words(wordDict.begin(), wordDict.end());
    f(0, currentAns, s, words);
    return result;
  }
};
