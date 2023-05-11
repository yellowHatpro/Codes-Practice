#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	int f(vector<int> &nums1, vector<int> &nums2, vector<vector<int>>& dp, int i, int j){
		if (i>=nums1.size() || j>=nums2.size()) return 0;
		if (dp[i][j]!=-1) return dp[i][j];
		int a = 0;
		if (nums1[i]==nums2[j]){
			a = 1 + f (nums1, nums2, dp, i+1,j+1);
		} else {
			a = max(f(nums1, nums2, dp, i+1,j), f(nums1, nums2, dp, i,j+1));
		}
		return dp[i][j]= a;
	}

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    	int n = nums1.size();
    	int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(nums1, nums2, dp,0,0);
    }
};