#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxFrequencyElements(vector<int> &nums) {
    map<int, int> m;
    for (auto itr : nums) {
      m[itr]++;
    }
    int maxFreq = INT_MIN;
    for (auto itr : m) {
      maxFreq = max(maxFreq, itr.second);
    }
    int cnt = 0;
    for (auto itr : m) {
      if (itr.second == maxFreq)
        cnt += itr.second;
    }
    return cnt;
  }
};
