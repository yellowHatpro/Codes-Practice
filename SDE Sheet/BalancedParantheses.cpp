#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
      for(int i = 0; i < s.size(); i++){
        if (s[i]=='(' || s[i]=='{' || s[i]=='['){
          st.push(s[i]);
        }
        else {
        if (st.empty()) return false;
        bool a = st.top()=='(' and s[i]!=')';
        bool b = st.top()=='[' and s[i]!=']';
        bool c = st.top()=='{' and s[i]!='}';
        if (a || b || c) return false;
        st.pop();
        }
      }
      return st.empty();
    }
};
