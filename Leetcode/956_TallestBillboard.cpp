#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int f(int i, int diff, vector<int>& rods, vector<vector<int>>& dp){
    if (i==rods.size()) return (!diff) ? 0 :  INT_MIN;
    if (dp[i][5000+diff]!=-1) return dp[i][5000+diff];
    int a = f(i+1,diff,rods,dp);
    int b =rods[i] + f(i+1,diff+rods[i],rods,dp);
    int c = f(i+1,diff-rods[i],rods,dp);
    return dp[i][5000+diff] = max({a,b,c});
    
  }

    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<vector<int>> dp(n, vector<int>(10000,-1));
        return f(0,0,rods,dp);
    }
};
