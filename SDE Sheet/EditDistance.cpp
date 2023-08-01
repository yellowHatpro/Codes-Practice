#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int f(string word1, string word2, int i, int j, vector<vector<int>>&dp){
      if (i<0 || j<0) return max(i+1,j+1);
      if (dp[i][j]!=-1) return dp[i][j];
      if (word1[i]==word2[j]) return dp[i][j] = f(word1,word2, i-1,j-1,dp);
      int a =  f(word1,word2,i-1,j,dp);
      int b =  f(word1,word2,i,j-1,dp);
      int c =  f(word1,word2,i-1,j-1,dp);
      return dp[i][j] =  min({a,b,c})+1;
  }

    int minDistance(string word1, string word2) {
      int n = word1.size();
      int m = word2.size();
      vector<vector<int>> dp(n,vector<int>(m,-1));
      return f(word1, word2, n-1,m-1,dp);
    }
};
