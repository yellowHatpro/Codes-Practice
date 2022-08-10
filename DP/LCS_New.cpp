#include <bits/stdc++.h>
using namespace std;

int f(string s,string t, vector<vector<int>> &dp,int i,int j){
	if (!s.size() || !t.size()) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	if(s[0]==t[0]) return dp[i][j] =  1 + f(s.substr(1),t.substr(1),dp,i-1,j-1);
	else{
		int a = f(s,t.substr(1),dp,i,j-1);
		int b = f(s.substr(1),t,dp,i-1,j);
		return dp[i][j] = max(a,b);
	}
}


int lcs(string s, string t){
	int n = s.size();
	int m = t.size();
	vector<vector<int>> dp(n,vector<int>(m,-1));
	return f(s,t,dp,n-1,m-1);
}

int main(int argc, char const *argv[])
{
	string a = "abcd";
	string b = "abd";
	cout<<lcs(a,b);
	return 0;
}