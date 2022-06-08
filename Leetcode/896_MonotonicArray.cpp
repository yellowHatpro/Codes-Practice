#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
    	bool isInc = nums[0]<=nums[nums.size()-1];
    	vector<int> v = nums;
    	if (isInc)
    	{	
    		sort(v.begin(), v.end());
    		return v==nums;
    	}
    	else{
    		sort(v.begin(), v.end(), greater<int>());
    		return v==nums;
    	}
    }
};