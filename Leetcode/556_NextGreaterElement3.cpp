#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
class Solution {
public:
    int nextGreaterElement(ull n) {
        if (n>=2147483486) return -1;
        string nums = to_string(n);
          if (nums.size()==1){
            return -1;
        }
        if (nums.size()==2) {
            if (nums[0]<nums[1]){
                swap(nums[0],nums[1]);
                           return stoull(nums);
            } else {
                return -1;
            }
        }
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
        	return -1;
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
           if (stoull(nums)>2147483647) return -1;
           return stoull(nums);
    }
};