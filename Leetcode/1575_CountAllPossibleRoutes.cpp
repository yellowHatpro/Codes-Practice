#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int mod = 1e9+7;
    
    int f(int st, int en, vector<vector<int>>&dp, int fuel, vector<int>&locations){
    int take = 0;
    if (st<0 || st>=locations.size() ||  fuel<0) return 0;
    if (st==en) take++;
    if (dp[st][fuel]!=-1) return dp[st][fuel];
    for (int i = 0; i < locations.size(); i++) {
      if (st!=i){
        take = (i>=0 && i<locations.size()) ? (take + f(i,en,dp,fuel-(abs(locations[st]-locations[i])), locations))%mod : 0;
      }
    }
    return dp[st][fuel] = (take)%mod;

  }
    

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {  
      int n = locations.size();    
      vector<vector<int>> dp(n+1,vector<int>(fuel+1,-1));
      return f(start,finish,dp,fuel,locations);
    }
};
