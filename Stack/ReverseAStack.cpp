#include <bits/stdc++.h>
using namespace std;
void reverseStack(stack<int> &s1, stack<int> &s2) {
  if (s1.size() <= 1) {
    return;
  }
  int below = s1.top();
  s1.pop();
  reverseStack(s1, s2);

  while (s1.size() != 0) {
    int res = s1.top();
    s1.pop();
    s2.push(res);
  }
  s2.push(below);
  while (s2.size() != 0) {
    int res = s2.top();
    s2.pop();
    s1.push(res);
  }
  return;
}
