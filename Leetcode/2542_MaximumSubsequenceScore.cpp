#include <bits/stdc++.h>
using namespace std;  

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        for (int i = 0; i < nums1.size(); i++){
          v.push_back({nums2[i],nums1[i]});
        }
      sort(v.begin(),v.end());
      long long ans = 0;
      long long sum = 0;
      priority_queue<int, vector<int>, greater<int>> q;
      for(int i = nums1.size()-1; i >= 0; i--){
        sum+= v[i].second;
        q.push(v[i].second);
        if (q.size()>k){
        sum-=q.top();
        q.pop();
      }
      if (q.size()==k) ans = max(ans,v[i].first * sum);
    }
    return ans;
    }
}; 
