#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int cnt = 0;
      int res = 0;
      for(int i = 0; i<nums.size(); i++){
        if (nums[i]==0) cnt=0;
        else {
          cnt++;
          res = max(res,cnt);
        }
      }
      return res;
    }
};
