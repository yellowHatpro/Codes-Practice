#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
      int cnt = 0;
      for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
          if ((long long)nums[i] > 2ll*(long long)nums[j]) cnt++;
        }
      }
    return cnt;
    }
};
