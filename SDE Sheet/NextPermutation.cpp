#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int n = nums.size();      
      if (n == 1) return ;
      if (n == 2) {
      reverse(nums.begin(), nums.end());
      return;
      }
      int justSmallerNumber = INT_MAX;
      for(int i = n-2; i >=0; i--){
        if (nums[i]<nums[i+1]){
        justSmallerNumber = i;
        break;
      }
    }
      if (justSmallerNumber == INT_MAX){
      reverse(nums.begin(), nums.end());
      return ;
    }
      int bigger = nums[justSmallerNumber+1];
      for(int i = justSmallerNumber+1; i < n; i++){
        if (nums[i]>nums[justSmallerNumber]){
          bigger = i;
      }
    }
      swap(nums[justSmallerNumber], nums[bigger]);
      reverse(nums.begin()+justSmallerNumber+1, nums.end());
      return;
      
    }
};
