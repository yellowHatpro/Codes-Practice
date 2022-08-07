#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size()-2; ++i)
        {
            int k=i+1;
            int l = nums.size()-1;
            if (i!=0 && nums[i]==nums[i-1]) continue;
            int remainingSum = 0 - nums[i];
            while(k<l){

                if (nums[k]+nums[l]==remainingSum){
                    res.push_back({nums[i],nums[k],nums[l]});
                    //Important Steps to Skip Duplicates
                    while(k<l && nums[k]==nums[k+1]) k++;
                    while(k<l && nums[l]==nums[l-1]) l--;
                    //--x--
                    k++;
                    l--;
                }
                else if (nums[k]+nums[l]>remainingSum){
                    l--;
                }
                else {
                    k++;
                }
            }
        }
        return res;
    }
};