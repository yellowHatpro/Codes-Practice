#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool isOutOfOrder(vector<int> a, int i){
        if (i==0) return a[i]>a[1];
        if(i==a.size()-1) return a[i]<a[i-1];
        return a[i]<a[i-1] or a[i]>a[i+1];
    }

    int findUnsortedSubarray(vector<int>& nums) {
        int largest = INT_MIN;
        int smallest= INT_MAX;
        for (int i = 0; i < nums.size()-1; ++i)
        {
            if (isOutOfOrder(nums,i)){
            largest = max(largest,nums[i]);
            smallest = min(smallest,nums[i]);
            }
        }
        if(smallest == INT_MAX){
            return 0;
        }
        int l = 0;
        int r = nums.size()-1;
        while(smallest>=nums[l]){
            l++;
        }
        while(largest<=nums[r]){
            r--;
        }
        return r-l+1;

    }
};