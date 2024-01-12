#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string reverseWords(string s) {
    string res;
    stack<string> st;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ')
        continue;
      string word;
      while (i < s.size() and s[i] != ' ') {
        word += s[i++];
      }
      st.push(word);
    }
    while (!st.empty()) {
      res += st.top();
      st.pop();
      if (!st.empty()) {
        res += ' ';
      }
    }
    return res;
  }
};
