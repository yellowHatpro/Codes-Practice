#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string minRemoveToMakeValid(string s) {
    int open = 0, close = 0;
    stack<char> st;
    // traverse from start to end to eleminate extra closing braces
    for (const char &c : s) {
      if (c != '(' && c != ')') {
        st.push(c);
      } else if (c == '(') {
        open++;
        st.push(c);
      } else if (open > 0) {
        st.push(c);
        open--;
      }
    }
    string ans;
    // traverse from left to right to remove extra opening braces
    open = 0, close = 0;
    while (!st.empty()) {
      char c = st.top();
      st.pop();
      if (c != '(' && c != ')') {
        ans += c;
      } else if (c == ')') {
        close++;
        ans += c;
      } else if (close > 0) {
        ans += c;
        close--;
      }
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
