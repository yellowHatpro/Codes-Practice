#include <bits/stdc++.h>
using namespace std;


//Type 1: DP on subsequence Rod Cutting : GFG
class Solution{
  public:

    int f(int*& price, int lim, vector<vector<int>>& dp, int i){
      if (lim==0) return 0;
      if (i==0){
        if (lim-i-1>=0) return lim*price[i];
    }
      if (dp[i][lim]!=-1) return dp[i][lim];
      int notTake = f(price,lim,dp,i-1);
      int take = INT_MIN;
      if (lim-i-1>=0){
        take = price[i] + f(price,lim-i-1, dp,i);
    }
    return dp[i][lim] =  max(take,notTake);
  }

    int cutRod(int price[], int n) {
        //states: i,n 
      vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
      return f(price,n,dp,n-1);
    }
};
//Type 2: DP on partitions Minimum Cost to cut a stick : leetcode
class SolutionLeetcode {
public:
    int f(int l, int r, vector<int>& cuts, vector<vector<int>>& dp){
     if (l>r) return 0;
     if (dp[l][r]!=-1) return dp[l][r];
     int mini = INT_MAX;
     for(int i = l; i <=r; i++){
      int ans = cuts[r+1] - cuts[l-1] + f(l,i-1,cuts,dp) + f(i+1,r,cuts,dp);
      mini = min(mini, ans);
    } 
    return dp[l][r] = mini;
  }

    int minCost(int n, vector<int>& cuts) {
      int m = cuts.size();
      cuts.push_back(n);
      cuts.insert(cuts.begin(),0);
      sort(cuts.begin(), cuts.end());
      vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
      return f(1,m,cuts,dp); 
    }
};

