#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxChunksToSorted(vector<int> &arr) {
    // this has to be monotonically increasing
    stack<int> s;
    for (auto itr : arr) {
      if (s.empty() || s.top() < itr) {
        s.push(itr);
      } else {
        int currentLargest = s.top();
        while (!s.empty() && s.top() > itr) {
          s.pop();
        }
        s.push(currentLargest);
      }
    }
    return s.size();
  }
};
