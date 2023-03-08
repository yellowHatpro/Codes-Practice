#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	int f(int i, int n, vector<vector<int>>& dp){
		if (i==0 || n==0) return 1;
		if (i>n) return f(i-1,n,dp);
		if (dp[i][n]!=-1) return dp[i][n];
		int take = i*f(i,n-i,dp);
		int notTake= f(i-1,n,dp);
		return dp[i][n]=max(take,notTake);
	}

    int integerBreak(int n) {
     	   vector<vector<int>> dp (n,vector<int>(n+1,-1));
     	   return f(n-1,n,dp);
    }
};