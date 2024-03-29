#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
         int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(1001, 1));

        int res = 1, diff;

        // Iterate over the elements in nums
        for(int ind = 0; ind < n; ind++){
            // Iterate over the previous elements
            for(int prev = 0; prev < ind; prev++){
                diff = nums[ind] - nums[prev];
                // Update the length of the arithmetic sequence with the current difference
                dp[ind][diff + 500] = max(dp[ind][diff + 500], 1 + dp[prev][diff + 500]);
                // Update the overall result with the maximum length so far
                res = max(res , dp[ind][diff + 500]);
            }
        }
        return res;    }
};
