#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string expression) {
  stack<char> s;
  for (int i = 0; i < expression.size(); ++i) {
    if (expression[i] == '(' or expression[i] == '{' or expression[i] == '[') {
      s.push(expression[i]);
    } else {
      if (s.empty()) {
        return false;
      } else if (expression[i] == '}' || expression[i] == ']' ||
                 expression[i] == ')') {

        if (expression[i] == ')') {
          if (s.top() == '(') {
            s.pop();
          } else {
            return false;
          }
        } else if (expression[i] == '}') {
          if (s.top() == '{') {
            s.pop();
          } else {
            return false;
          }
        } else if (expression[i] == ']') {
          if (s.top() == '[') {
            s.pop();
          } else {
            return false;
          }
        }
      }
    }
  }
  return s.empty();
}
