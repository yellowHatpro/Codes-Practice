#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int trailingZeroes(int N) {
    int cnt = 0;
    int fives = 5;
    while (fives <= N) {
      cnt += (N / fives);
      fives *= 5;
    }
    return cnt;
  }
};
