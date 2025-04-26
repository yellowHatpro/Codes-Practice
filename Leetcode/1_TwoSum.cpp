#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> hash;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      int another = target - nums[i];
      if (hash.find(another) != hash.end()) {
        res.push_back(hash[another]);
        res.push_back(i);
      } else {
        hash[nums[i]] = i;
      }
    }
    return res;
  }
};
