#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void f(vector<int>& nums, set<vector<int>>&res, int i, vector<int>& v){
      if (i==nums.size()){
        res.insert(v);
        return;
      }
      v.push_back(nums[i]);
      f(nums,res,i+1,v);
      v.pop_back();
      f(nums,res,i+1,v);
  }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      set<vector<int>> res;
      vector<int> v;
      f(nums,res,0,v);
      vector<vector<int>> ans(res.begin(),res.end());
      return ans;
    }
};

