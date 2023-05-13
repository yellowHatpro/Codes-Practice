#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	int f (int low, int high, int zero, int one, vector<int>& dp, int i) {
		if (i<=0) return 1;
		if (dp[i]!=-1) return dp[i];
		int total = 0;
		if (i-zero>=0) total+= f(low, high, zero, one, dp, i-zero);
		if (i-one>=0) total+= f(low, high, zero, one, dp, i-one);
		return dp[i] = total % (int)(1e9+7);
	}

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        int ans = 0;
        for (int i = low; i<=high; i++) {
        	ans += f(low, high, zero, one, dp, i);
					ans%=(int)(1e9+7);
        }
        return ans;
    }
};