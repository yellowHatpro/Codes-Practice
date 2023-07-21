#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void f(vector<vector<int>>&s, vector<int>& c, int x, int i, vector<int>& v){
        if (x==0){
          s.push_back(v);
          return;
      }
      for (int idx = i; idx< c.size(); idx++){
        if (idx>i && c[idx]==c[idx-1] ) continue;
        if (c[idx]>x) break;
        v.push_back(c[idx]);
        f(s,c,x-c[idx],idx+1,v);
        v.pop_back();
    }
      }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      vector<vector<int>> ans;
      vector<int> v;
      f(ans, candidates, target,0,v);
      return ans;
  }
};
