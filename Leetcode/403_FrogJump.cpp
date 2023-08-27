#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    unordered_map<int,int> m;
    bool f( vector<int>&stones , int n, vector<vector<int>>&dp, int lastJump, int i){
      if (i==n-1) return 1;
      if (dp[lastJump][i]!=-1) return dp[lastJump][i];
      bool ans = false;
      for(int idx = -1; idx <=1; idx++ ){
        if (lastJump+idx<=0) continue;
        if (m.find(lastJump+idx+stones[i])!=m.end()){
          ans |=f(stones,n,dp,lastJump+idx,m[lastJump+idx+stones[i]]);
      }
    }
      return dp[lastJump][i] = ans;
  }

    bool canCross(vector<int>& stones) {
      int n = stones.size();
      for(int i = 0; i<n; i++) m[stones[i]] = i;
      int maxSize = stones[n-1];
      vector<vector<int>> dp = vector<vector<int>>(2001,vector<int>(2001,-1));
      return f(stones,n,dp,0,0);
    }
};
