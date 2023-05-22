#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      if (k==nums.size()) {
          return nums;
      } 
      map<int,int> m;
      for(auto n : nums) {
        m[n]++;
      }
      auto comp = [&m](int n1, int n2) { return m[n1]>m[n2];};
      priority_queue<int, vector<int>,decltype(comp)> heap(comp);
    for(pair<int,int> p : m){
      heap.push(p.first);
      if (heap.size()>k) heap.pop();
    }
    vector<int> top(k);
    for(int i = k-1; i>=0; i--){
      top[i]=heap.top();
      heap.pop();
    }
    return top;
    }
};
