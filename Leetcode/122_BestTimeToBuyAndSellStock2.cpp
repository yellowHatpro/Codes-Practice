#include <bits/stdc++.h>
using namespace std;
class SolutionDP {
public:
    int maxProfit(vector<int>& prices) {
    	int n = prices.size();
        vector<int> dp(n);
        int currMax = prices[0];
        for(int i = 1; i<n;i++){
        	dp[i] = max(dp[i-1],dp[i-1]-currMax+ prices[i]);
            currMax = prices[i];
        }
        return dp[n-1];
    }
};
//O1 space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int n = prices.size();
        int currMax = prices[0];
        int maxSoFar = 0;
        for(int i = 1; i<n;i++){
        maxSoFar = max(maxSoFar,maxSoFar-currMax+ prices[i]);
            currMax = prices[i];
        }
        return maxSoFar;
    }
};