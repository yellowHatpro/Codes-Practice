#include <bits/stdc++.h>
using namespace std;
bool checkRedundantBrackets(string input) {
  stack<int> s;
  for (int i = 0; i < input.size(); ++i) {
    int cnt = 0;
    while (input[i] != ')') {
      s.push(input[i++]);
    }
    while (s.top() != '(') {
      cnt++;
      s.pop();
    }
    if (cnt <= 1) {
      return true;
    } else {
      s.pop();
    }
  }
  return false;
}
