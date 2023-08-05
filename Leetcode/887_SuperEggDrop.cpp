#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    int fn(int e, int f, vector<vector<int>>&dp){
      if (f==0||f==1||e==1) return f;
      if (dp[e][f]!=-1) return dp[e][f];
      int minAttempts = INT_MAX;
      int l = 1;
      int r = f;
      while(l<=r){
        int m = (l+r)/2;
        int broke = fn(e-1,m-1,dp);
        int notBroke = fn(e,f-m,dp);
        minAttempts = min(minAttempts,1+max(broke,notBroke));
        if (broke<notBroke) l = m + 1;
        else r = m - 1;
    }
    return dp[e][f] = minAttempts;
  }

    int superEggDrop(int n, int k) {
      vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
      return fn(n,k,dp);
    }
};
