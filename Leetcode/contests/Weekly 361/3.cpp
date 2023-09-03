#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
      long long totalcnt = 0;
      int prefix = 0;
      int n = nums.size();
      map<long long, long long> m;
      m[0]++;
     for (int i = 0; i < n; i++) {
      if (nums[i]%modulo==k) prefix++;
      prefix%=modulo;
      if (m.find((prefix-k+modulo)%modulo)!=m.end()) totalcnt+=m[(prefix-k+modulo)%modulo];
      m[prefix]++;
     } 
      return totalcnt;
    }
};
