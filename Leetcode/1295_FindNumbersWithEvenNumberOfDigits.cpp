#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // given a positive integer x,
  // the number of digits in x is floor(log10(x)) + 1
  int findNumbers(vector<int> &nums) {
    int ans = 0;
    for (int itr : nums) {
      int digits = floor(log10(itr)) + 1;
      ans += (digits % 2 == 0);
    }
    return ans;
  }
};
