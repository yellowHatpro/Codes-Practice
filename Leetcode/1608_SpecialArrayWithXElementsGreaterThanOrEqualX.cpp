#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int specialArray(vector<int>& nums) {
              sort(nums.begin(),nums.end());
        int k=1,i=0;
        while(i<nums.size())
        {
            if(nums[i]>=k)
            {
                if(nums.size()-i==k)
                {
                    return k;
                }
                k++;
            }
            else
            {
                i++;   
            }
        }
        return -1;
    }
};