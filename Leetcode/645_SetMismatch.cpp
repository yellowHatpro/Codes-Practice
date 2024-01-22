#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    int n = nums.size();
    int actualSum = n * (n + 1) / 2;
    map<int, int> m;
    int repeated = 0;
    for (auto itr : nums) {
      m[itr]++;
      if (m[itr] == 2) {
        repeated = itr;
        break;
      }
    }
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int diff = actualSum - sum;
    return {repeated, repeated + diff};
  }
};
