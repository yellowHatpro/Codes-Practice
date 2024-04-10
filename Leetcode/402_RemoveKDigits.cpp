#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k) {
    stack<char> st;
    string res = "";
    for (auto ch : num) {
      while (!st.empty() and k > 0 and st.top() > ch) {
        st.pop();
        k--;
      }
      st.push(ch);
    }
    while (k > 0 and !st.empty()) {
      st.pop();
      k--;
    }
    while (!st.empty()) {
      res += st.top();
      st.pop();
    }
    reverse(res.begin(), res.end());
    int non_zero_idx = 0;
    while (res[non_zero_idx] == '0') {
      non_zero_idx++;
    }
    res = res.substr(non_zero_idx);
    return res.size() >= 1 ? res : "0";
  }
};
