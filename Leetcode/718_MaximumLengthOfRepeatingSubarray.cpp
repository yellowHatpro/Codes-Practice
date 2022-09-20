#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int mx = INT_MIN;
	int dp[1005][1005];
	int f(vector<int>& nums1, int i, vector<int>&nums2, int j){
		if (i == nums1.size() || j == nums2.size()) return 0;
		if (dp[i][j]!=-1) return dp[i][j];
		int len = 0;
		if(nums1[i]==nums2[j]) len = 1 + f(nums1,i+1,nums2,j+1);
		f(nums1,i,nums2,j+1);
		f(nums1,i+1,nums2,j);
		mx = max(mx,len);
		return dp[i][j] = len;
	}

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        memset(dp,-1,sizeof(dp));
        f(nums1,0,nums2,0);
        return mx;
    }
};