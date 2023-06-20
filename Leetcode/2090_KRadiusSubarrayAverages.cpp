#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(),-1);
        int l = 0;
        long long int sum = 0;
        for (int r  = 0; r  < nums.size(); ++r ) {	
            sum+=nums[r];
        	if((2*k)<=r){
        		ans[r-k] = sum/(2*k + 1);
        		sum-=nums[l++];
        	} else {
                continue;
            }
        }
        return ans;
    }
};