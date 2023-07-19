#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void f(vector<vector<int>>&res, vector<int>&c, int target, int i, vector<int>& v){
    if (i==c.size()){
      if (target==0){
        res.push_back(v);
      }
        return;
    }
    if (c[i]<=target){
      v.push_back(c[i]);
      f(res,c,target-c[i],i,v);
      v.pop_back();
    }
    f(res,c,target,i+1, v);
  }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> res;
      vector<int> v;
      f(res,candidates,target,0,v);
      return res;
    }
};
