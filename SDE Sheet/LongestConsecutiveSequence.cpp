#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int cnt = 0;
      unordered_set<int> s = {nums.begin(), nums.end()};
      for(auto itr: nums){
        if (s.find(itr-1)!=s.end()) continue;
        else {
        int cnti = 0; 
        while(s.find(cnti+itr)!=s.end()){
          cnti++;
        }
        cnt = max(cnt, cnti);
      }
    }
    return cnt;
    }
};
