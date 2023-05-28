#include <bits/stdc++.h> 


    int f(int i, int j, vector<vector<int>>& dp, vector<int> &cuts) {
        if (i>j) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        int cost = 0;
        int mini = INT_MAX;
        for(int idx = i; idx<=j; idx++){
          cost = cuts[j+1] - cuts[i-1] + f(i, idx-1, dp,cuts) + f(idx+1, j, dp, cuts);
        mini = min(mini, cost);
      }
      return dp[i][j] = mini;
    };

    int cost(int n, int m,  vector<int>& cuts) {
      cuts.push_back(0);
      cuts.push_back(n);
      sort(cuts.begin(), cuts.end());
      vector<vector<int>> dp(m+1, vector<int>(m+1,-1));
      
    return f(1,m, dp, cuts);
  }
