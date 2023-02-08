#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	//dp[i] is the min no of jumps to reach pos i
    int jump(vector<int>& nums) {
    	if (nums.size()==1) return 1;
    	int n = nums.size();
        vector<int> dp(n,INT_MAX);
        dp [0] = 0;

        for (int i = 0; i < n-1; ++i)
        {
        	for (int j = 0; j <= nums[i]; ++j)
        			{  if (i+j>=n) break;
        				dp[i+j] = min(dp[i+j],dp[i]+1); 
        			}		
        }
        return dp[n-1];
    }
};