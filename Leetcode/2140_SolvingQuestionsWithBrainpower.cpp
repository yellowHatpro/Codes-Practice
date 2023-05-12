#include <bits/stdc++.h>
using namespace std;
class Solution {
public:


	long long f (vector<vector<int>>& questions, vector<long long>& dp, int i){
		if (i>=questions.size()) return 0;
		if (dp[i]!=-1) return dp[i];
		long long take = questions[i][0] + f(questions,dp,i+questions[i][1]+1);
		long long notTake = f(questions,dp,i+1);
		return dp[i]=max(take,notTake);
	}
    long long mostPoints(vector<vector<int>>& questions) {
    	int n = questions.size();
        vector<long long> dp(n,-1);
        return f(questions,dp,0);
    }
};