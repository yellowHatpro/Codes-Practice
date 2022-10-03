#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int f(string s, int i, vector<int>&dp){
		if (i>=s.size()) return 1;
		if (dp[i]!=-1) return dp[i];
		int a = s[i] - '0';//gives integer value for 0<=s[0]<=9
		int b = 0;
		if(i<s.length()-1) b = a*10 + (s[i+1] - '0' );
		int ans = 0;
		if (a>0) ans+=f(s,i+1,dp);
		if (a!=0 &&b>0 && b<=26) ans+=f(s,i+2,dp);
		return dp[i] =  ans; 
	}
    int numDecodings(string s) {
    	vector<int> dp(-1,s.length());
		return f(s,0,dp) ;

    }
};