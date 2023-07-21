#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void f(vector<int>&nums, vector<vector<int>>&res,int i){
      if (i==nums.size()){
        res.push_back(nums);
        return;
      }
      for(int j = i; j < nums.size(); j++){
        swap(nums[i],nums[j]);
        f(nums,res,i+1);
        swap(nums[i],nums[j]);
      }
    }

    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      f(nums,res,0);
      return res;
    }
};
