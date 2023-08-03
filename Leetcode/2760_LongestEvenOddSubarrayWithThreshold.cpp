#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
      int l = 0;
      int ans = 0;
      for(int r = 0; r < nums.size(); r++){
        if (nums[l]%2==0 && nums[l]<=threshold){
          while( r<nums.size()-1 &&  nums[r]%2 != nums[r+1]%2 && nums[r+1]<=threshold) r++;
          ans = max(ans,r-l+1);
          l = r+1;
        } else {
        while( l < nums.size() && (nums[l]%2!=0 || nums[l]>threshold)) l++;
        if (l>r) r = l-1;
        }
      }
      return ans;
    }
};
