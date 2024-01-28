#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    map<int, int> m;
    int prefixSum = 0;
    int cnt = 0;
    m[0]++;
    for (auto itr : nums) {
      prefixSum += itr;
      if (m[prefixSum - k] != 0) {
        cnt += m[prefixSum - k];
      }
      m[prefixSum]++;
    }
    return cnt;
  }
};
