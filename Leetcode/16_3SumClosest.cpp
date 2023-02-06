#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size()-2; ++i)
        {
        	   int l = i+1;
        		int r = nums.size()-1;

        	while(l<r){
        		int newsum = nums[i] + nums[l] + nums[r];
        	if (abs(newsum - target)<abs(target-sum)){
        		sum = newsum;
        	}
        		if (newsum>target){
        			r--;
        		} else{
        			l++;
        		}
        	}
        }
        return sum;
    }
};