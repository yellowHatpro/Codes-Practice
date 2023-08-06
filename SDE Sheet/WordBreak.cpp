#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool f(string s, vector<int>&dp, set<string>& words, int i, int n){
      if (i==n) return true;
      if (dp[i]!=-1) return dp[i];
      for(int j = i; j <n; j++){
        string word = s.substr(i,j-i+1);
        if (words.find(word)!=words.end()){
          if (f(s,dp,words,j+1,n)) return dp[i] = true;
      }
    }
    return dp[i] = false;
  }

    bool wordBreak(string s, vector<string>& wordDict) {
      vector<int> dp(s.size(),-1);
      set<string> words(wordDict.begin(), wordDict.end());
      return f(s,dp,words,0,s.size());
    }
};
