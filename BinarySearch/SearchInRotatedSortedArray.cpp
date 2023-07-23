#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n = nums.size();
      int l = 0;
      int r = n-1;
      while(l<=r){
        int m = (l+r)/2;
        if (nums[m]==target) return m;
        if (nums[l]<=nums[m]){
          if (nums[l]<=target && nums[m]>=target) r =m-1;
          else l = m+1;
        }
        else {
          if (nums[m]<=target && nums[r]>=target) l = m+1;
          else r = m-1;
        }
      }
      return -1;
    }
};
