#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    if (sx == fx && sy == fy) {
      return (t != -1);
    }
    int x = abs(sx - fx);
    int y = abs(sy - fy);
    return max(x, y) <= t;
  }
};
