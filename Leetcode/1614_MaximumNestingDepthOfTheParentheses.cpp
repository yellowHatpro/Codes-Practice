#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxDepth(string s) {
    int ans = 0;
    int cnt = 0;

    for (char ch : s) {
      if (ch == '(') {
        cnt++;
        ans = max(ans, cnt);
      } else if (ch == ')') {
        cnt--;
      }
    }

    return ans;
  }
};
