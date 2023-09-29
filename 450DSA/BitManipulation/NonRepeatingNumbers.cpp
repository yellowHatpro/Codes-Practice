#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> singleNumber(vector<int> nums) {
    int totalXOR = 0;
    for (auto it : nums) {
      totalXOR ^= it;
    }
    int x = 0;
    int y = 0;
    int rightSetBit = totalXOR & -totalXOR;
    for (auto itr : nums) {
      if (itr & rightSetBit)
        x ^= itr;
      else
        y ^= itr;
    }
    return {min(x, y), max(x, y)};
  }
};
