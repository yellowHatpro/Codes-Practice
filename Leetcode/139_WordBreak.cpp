#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	bool f(string s, set<string> words, int i, vector<int>& dp){
		if (i==s.size()) return true;
		if (dp[i]!=-1) return dp[i];
		for (int j = i; j<s.size();j++){
			if (words.find(s.substr(i,j-i+1))!=words.end()){
				if (f(s,words, j+1, dp)) return dp[i] = true;
			}
		}
		return dp[i] = false;
	}

    bool wordBreak(string s, vector<string>& wordDict) {
       set<string> words(wordDict.begin(), wordDict.end());
       int n = s.size();
       vector<int> dp(n,-1);
       return f(s,words,0,dp);
    }
};