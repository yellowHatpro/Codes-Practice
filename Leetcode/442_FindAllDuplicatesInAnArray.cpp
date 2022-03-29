#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> arr = {};
        for (int i = 0; i < nums.size(); ++i)
        {
            int index = abs(nums[i]) -1 ;
            if (nums[index]<0)
            {
                arr.push_back(abs(nums[i]));
            }
            else {
            nums[index] = -1 * nums[index];
            }
        }
        return arr;
    }
};