#include <bits/stdc++.h>
using namespace std;

//Using set 
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
  using tiii = tuple<int,int,int>;
  set<tiii> s;
  s.insert({nums1[0]+nums2[0], 0, 0});
  vector<vector<int>> ans;
  while(!s.empty() && ans.size() < k){
      auto [sum, i1, i2] = *s.begin();
      s.erase(s.begin());
      ans.push_back({nums1[i1],nums2[i2]});
      if (i1!=nums1.size()-1) s.insert({nums1[i1+1]+nums2[i2], i1+1,i2});
      if (i2!=nums2.size()-1) s.insert({nums1[i1]+nums2[i2+1], i1,i2+1});
    }
    return ans;
  }
};

