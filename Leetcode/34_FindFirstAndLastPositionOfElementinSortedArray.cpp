//2 times binary search to find the 2 indices

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        vector<int> res(2,-1);
        int mid = 0;
        while(lo<=hi){
        	mid = hi - (hi-lo)/2;
        	if (nums[mid]==target)
        	{	res[0] = mid;
        		hi = mid-1;
        			
        	}
        	else if (nums[mid]>target){
        		hi = mid -1;
        	}
        	else{
        		lo = mid+1;
        	}
        }
        lo = 0;
        hi = nums.size()-1;
        while(lo<=hi){
        	mid = hi - (hi-lo)/2;
        	if (nums[mid]==target)
        	{	res[1] = mid;
        		lo = mid+1;
        			
        	}
        	else if (nums[mid]>target){
        		hi = mid -1;
        	}
        	else{
        		lo = mid+1;
        	}
        }

        return res;
    }
};