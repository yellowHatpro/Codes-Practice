#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> findMatrix(vector<int> &nums) {
    map<int, int> freq;
    vector<vector<int>> res;
    for (int num : nums) {
      if (freq[num] >= res.size()) {
        res.push_back({});
      }
      res[freq[num]].push_back(num);
      freq[num]++;
    }
    return res;
  }
};
