#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size()==1){
            return;
        }
        if (nums.size()==2) {swap(nums[0],nums[1]);
                           return;}
    	int index = -1;
    	int just_bigger_index = -1;
        for (int i = nums.size()-2; i>=0; i--)
        {
        	if (nums[i]<nums[i+1])
        	{
        		index=i;
                break;
        	}
        }
          if (index==-1)
        {
        	reverse(nums.begin(),nums.end());
              return;
        }
        for (int i = nums.size()-1; i >index; i--)
        {
        	if (nums[i]>nums[index])
        	{
        		just_bigger_index = i;
                break;
        	}
        }
        swap(nums[index],nums[just_bigger_index]);

           reverse(nums.begin() + index + 1, nums.end());
    }
};