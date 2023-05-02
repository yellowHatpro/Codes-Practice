#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int f(int n, vector<int> &cost, vector<int>& dp){
        if (n<0) return dp[0] = 0;
        if (n==0) return dp[n] = cost[0];
        if (dp[n]!=-1) return dp[n];
        int a = cost[n] +  f(n-1,cost, dp);
        int b = cost[n] + f(n-2, cost, dp);
        return dp[n] = min({a,b});
    }

    int minCostClimbingStairs(vector<int>& cost) {
       
        int n = cost.size();
         vector<int> dp(n);
         for (int i = 2; i<n;i++){
            cost[i] = min(cost[i-1], cost[i-2]); 
         }
        return min(f(n-1,cost,dp), f(n-2, cost,dp));
    }
};

class SolutionDP {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> v(n);
        v[0] = cost[0];
        v[1] = cost[1];
        for (int i = 2; i < n; ++i)
        {
            v[i] = cost[i] + min(v[i-1],v[i-2]);
        }
        return min(v[n-1], v[n-2]);
    }
};