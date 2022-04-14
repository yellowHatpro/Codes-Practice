#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int searchFn(vector<int> nums, int target, int low, int high){
		if (low>high) return -1;
		int mid = low + (high-low)/2;
		if (nums[mid]==target)
		{
			return mid;
		}
		if(nums[mid]>=nums[low]){
			if (target>=nums[low]&&target<=nums[mid])
			{
				return searchFn(nums,target,low,mid-1);
			}else{
				return searchFn(nums,target,mid+1,high);
			}
		}
		else{
			if (target>=nums[mid]&target<=nums[high])
			{
				searchFn(nums,target,mid+1,high);
			}else{
				searchFn(nums,target,low,mid-1);
			}

		}
	}

    int search(vector<int>& nums, int target) {
      cout<<  searchFn(nums,target,0,nums.size()-1);
    }
};