#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findPosition(int n) {
    if (n > 0) {
      if (!(n & (n - 1))) {
        int mask = n & -n;
        int cnt = 1;
        while (mask != 1) {
          mask = mask >> 1;
          cnt++;
        }
        return cnt;
      }
    }
    return -1;
  }
};
