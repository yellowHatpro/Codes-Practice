#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int prefix = 1;
      int suffix = 1;
      int ans = INT_MIN;
      int n = nums.size();
      for(int i=0; i<n; i++){
        if (prefix==0) prefix = 1;
        if (suffix==0) suffix = 1;
        prefix*=nums[i];
        suffix*=nums[n-i-1];
        ans = max({ans,prefix,suffix});
      }
      return ans;
    }
};
