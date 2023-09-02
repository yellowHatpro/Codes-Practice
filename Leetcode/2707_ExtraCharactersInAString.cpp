#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int f(map<string,bool>&dict, string&s, int i, vector<int>&dp, int n){
      if (i==n) return 0;
      if (dp[i]!=-1) return dp[i];
      int res = 1 + f(dict,s,i+1,dp,n);
      for(int j = i; j < n; j++){
        if (dict[s.substr(i,j+1-i)]){
          res = min(res,f(dict,s,j+1,dp,n));
        }
      }
      return dp[i] = res;

  }

    int minExtraChar(string s, vector<string>& dictionary) {
      int n = s.size();
      map<string,bool> dict;
      for(auto itr: dictionary){
        dict[itr] = true;
      }
      vector<int> dp(n+2,-1);
      return f(dict,s,0,dp,n);
    }
};
