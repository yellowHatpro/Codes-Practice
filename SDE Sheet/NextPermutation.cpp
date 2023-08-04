#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int n = nums.size();      
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
      for(int i = n-1; i > justSmallerNumber; i--){
        if (nums[i]>nums[justSmallerNumber]){
          swap(nums[i],nums[justSmallerNumber]);
          break;
      }
    }
      reverse(nums.begin()+justSmallerNumber+1, nums.end());
      return;
    }
};
