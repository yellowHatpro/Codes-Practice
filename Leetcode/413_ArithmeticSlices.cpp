#include <bits/stdc++.h>
using namespace std;
class SolutionSpaceON {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n<3) return 0;
        vector<int> dp(n,0);
        for (int i = 2; i<n;i++){
        	if (nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
        		dp[i] = 1+dp[i-1];
        	}
        }
        int ans = 0;
        for(auto itr: dp){
        	ans+=itr;
        }
        return ans;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n<3) return 0;
        int ans = 0;
        int cnt = 0;
        for (int i = 2; i<n;i++){
        	if (nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
        		cnt++;
                ans+=cnt;
        	} else {
        		cnt = 0;
        	}
        }
        return ans;
    }
};