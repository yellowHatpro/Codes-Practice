#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = -1;
        int r = nums.size();
        while(r>l+1){
            int m = (l+r)/2;
            if (nums[m]>=target) r = m;
            else l = m;
        }
        return l+1;
    }
};