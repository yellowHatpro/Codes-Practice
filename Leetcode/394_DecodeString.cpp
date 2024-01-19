#include <bits/stdc++.h>
using namespace std;

// General idea is to push everything to stack until we get a ']'
// We are pushing strings to stack, because we are also pushing the resulting
// substrings ex: 3[a2[c]] : first 2[c] will be converted to "cc", so we push to
// stack, because the substring "cc" is also the part of the outer operation,
// here 3[acc]
// Thus, some extra code is written in order to compensate adding strings to
// stack

class Solution {
public:
  string decodeString(string s) {
    string res;
    stack<string> stck;
    for (auto ch : s) {
      if (ch != ']') {
        string x;
        x += ch;
        stck.push(x);
      } else {
        string substring;
        while (stck.top() != "[") {
          substring = stck.top() + substring;
          stck.pop();
        }
        stck.pop();
        string k;
        while (!stck.empty() and (stck.top().size() == 1) and
               isdigit(stck.top()[0])) {
          k = stck.top() + k;
          stck.pop();
        }
        int ktimes = stoi(k);
        string finalStringToBeAppendedToStackTop;
        for (int i = 0; i < ktimes; i++) {
          finalStringToBeAppendedToStackTop += substring;
        }
        stck.push(finalStringToBeAppendedToStackTop);
      }
    }
    while (!stck.empty()) {
      res = stck.top() + res;
      stck.pop();
    }
    return res;
  }
};
