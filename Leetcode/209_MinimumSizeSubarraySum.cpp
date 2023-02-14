//Sliding Window Problem

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int l = 0;
       int ans = INT_MAX;
       int totalSum = 0;
       for (int r = 0; r < nums.size(); ++r)
       {
         totalSum+=nums[r];
         while((totalSum - nums[l]>=target)){
            totalSum-=nums[l];
            l++;
         }    
         if (totalSum>=target){
            ans = min(ans, r-l+1);
         }
       }
       return ans;
    }
};