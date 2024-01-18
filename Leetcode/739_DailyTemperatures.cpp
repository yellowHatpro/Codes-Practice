#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    stack<pair<int, int>> s;
    int cnt = 0;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
      if (s.empty()) {
        ans[i] = 0;
      } else {
        cnt = 1;
        if (s.top().first > temperatures[i])
          ans[i] = 1;
        else {
          while (!s.empty() and s.top().first <= temperatures[i]) {
            cnt += s.top().second;
            s.pop();
          }
          if (s.empty()) {
            ans[i] = 0;
          } else {
            ans[i] = cnt;
          }
        }
      }
      s.push({temperatures[i], cnt});
    }
    return ans;
  }
};
