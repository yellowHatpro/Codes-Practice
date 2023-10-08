#include <bits/stdc++.h>
using namespace std;
int main() {
  priority_queue<int> left;                             // max heap
  priority_queue<int, vector<int>, greater<int>> right; // min heap
  int prompt;
  cin >> prompt;
  left.push(prompt);

  float med = prompt;
  cout << med << " ";

  cin >> prompt;
  while (prompt != -1) {
    if (left.size() > right.size()) {
      if (prompt >= med) {
        right.push(prompt);
      } else {
        left.push(prompt);
        right.push(left.top());
        left.pop();
      }
      med = (left.top() + right.top()) / 2.0;
    } else if (left.size() == right.size()) {
      if (prompt < med) {
        left.push(prompt);
        med = left.top();
      } else {
        right.push(prompt);
        med = right.top();
      }
    } else {
      if (prompt >= med) {
        right.push(prompt);
        left.push(right.top());
        right.pop();
      } else {
        left.push(med);
      }
      med = (left.top() + right.top()) / 2.0;
    }
    cout << med << " ";
    cin >> prompt;
  }
  return 0;
}
