#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class Solution {
  public:
    int setBits(int N) {
      int cnt = 0;
      for (int i = 0; i <= 30; i++) {
        cnt+=(N&(1<<i))>>i;
      }
    return cnt;
  }
};

//Another methods:
// 1. __builtin_popcount(int n)
