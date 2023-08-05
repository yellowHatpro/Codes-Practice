#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    int fn(int e, int f, vector<vector<int>>&dp){
      if (f==0||f==1||e==1) return f;
      if (dp[e][f]!=-1) return dp[e][f];
      int minAttempts = INT_MAX;
      for(int floor = 1; floor<=f; floor++){
        int broke = fn(e-1,floor-1,dp);
        int notBroke = fn(e,f-floor,dp);
        minAttempts = min(minAttempts,1+max(broke,notBroke));
    }
    return dp[e][f] = minAttempts;
  }

    int eggDrop(int n, int k) {
      vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
      return fn(n,k,dp);
    }
};
