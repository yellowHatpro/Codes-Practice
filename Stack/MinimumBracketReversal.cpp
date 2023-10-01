#include <bits/stdc++.h>
using namespace std;
int countBracketReversals(string input) {
  int n = input.size();
  if (n % 2 != 0) {
    return -1;
  }
  stack<int> s;

  // This part intuitive
  for (int i = 0; i < n; ++i) {
    if (s.empty()) {
      s.push(input[i]);
    } else {
      if (s.top() == '{' && input[i] == '}') {
        s.pop();
      } else {
        s.push(input[i]);
      }
    }
  }

  // This part to think, if "{{" or "}}" then cnt++, else "}{" remains so
  // cnt+=2..
  int cnt = 0;
  while (!s.empty()) {
    int a = s.top();
    s.pop();
    int b = s.top();
    s.pop();
    if (a == b) {
      cnt++;
    } else {
      cnt += 2;
    }
  }
  return cnt;
}
