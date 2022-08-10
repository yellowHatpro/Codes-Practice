#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	int f(string word1, string word2, vector<vector<int>>&dp,int i,int j){
		if(!word1.size() || !word2.size()) return max(word1.size(),word2.size());
		if(dp[i][j]!=-1) return dp[i][j];

		if(word1[0]==word2[0]) return dp[i][j]= f(word1.substr(1),word2.substr(1),dp,i-1,j-1);
		else{
			int a = f(word1.substr(1),word2.substr(1),dp,i-1,j-1);
			int b = f(word1,word2.substr(1),dp,i,j-1);
			int c = f(word1.substr(1),word2,dp,i-1,j);
			return dp[i][j] = min({a,b,c}) +1;
		}
	}

    int minDistance(string word1, string word2) {
    	int n = word1.size();
    	int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(word1,word2,dp,n-1,m-1);
    }
};