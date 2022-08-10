#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	int f(string t1,string t2, vector<vector<int>>&dp,int i,int j){
		if(!t1.size()||!t2.size()) return 0;
		if(dp[i][j]!=-1) return dp[i][j];
		if(t1[i]==t2[j]) return dp[i][j] = 1 + f(t1,t2,dp,i-1,j-1);
		else{
			int a = f(t1,t2,dp,i-1,j);
			int b = f(t1,t2,dp,i,j-1);
			return dp[i][j] = max(a,b);
		}

	}

    int longestCommonSubsequence(string t1, string t2) {
    	int n = t1.size();
    	int m = t2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(t1,t2,dp,n-1,m-1);
    }
};