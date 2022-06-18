#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for (int i = 0; i < nums.size(); ++i)
        {
        	sum+=nums[i];
        }        
    	int leftSum = 0;
    	int rightSum = sum;
    	int idx = 0;
    	while(idx<nums.size()) {
    		if (idx!=0)
    		{
    			leftSum+=nums[idx-1];
    		}
    		rightSum-=nums[idx];
    		if (leftSum==rightSum)
    		{
    			return idx;
    		}
    		idx++;
    	}
    	return -1;
    }
};