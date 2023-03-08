#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    	int peak = 1;
    	int valley = 1;
    	for(int i =1; i<nums.size();i++){
    		if (nums[i]>nums[i-1]) peak = valley+1;
    		else if (nums[i]<nums[i-1]) valley = peak+1;
    	}
    	return max(peak,valley);
    }
};

/* peak = valley+1 is a clever approach, whenever there is a sequence like 1 2 3 4 (strictly increasing or decreasing), 
 peak will pause at valley + 1, because the same if condition (like for 1 2 3 4, nums[i]>nums[i-1] will hit) valley will be same only
so peak will at valley + 1. We have kind of locked the answer at prev+1, and when there will be change in sequence (like 1 2 3 4 -> 5), 
 now another else if condition will hit, but now peak is increased, so valley will continue from increased answer.
Nice work Karan Zaildar.*/