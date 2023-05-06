#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int mod = 1000000007;
        vector<int> power_of_2(n);
        power_of_2[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            power_of_2[i]=(2*power_of_2[i-1])%mod;
        }
        sort(nums.begin(), nums.end());
        int ans = 0;
        int l = 0, r = n-1;
        while(l<=r){
            if (nums[l] + nums[r]<=target){
                ans+=power_of_2[r-l];
                ans%=mod;
                l++;
            } else r--;
        }
        return ans;
    }
};