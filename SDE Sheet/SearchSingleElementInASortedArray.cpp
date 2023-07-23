#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      int l = 0;
      int r = nums.size()-1;
      for(int i = 0; i < 70; i++){
        int m = (l+r)/2;
        if (m%2){
          if (nums[m]==nums[m-1]){
            l = m+1;
          }
          else r = m;
        }
        //even position
        else {
          if (m!=0 && nums[m]==nums[m-1]){
            r = m-1;
          } else l = m;
        }
      }
      return nums[l];
    }
};
