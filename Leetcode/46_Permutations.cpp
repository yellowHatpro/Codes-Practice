#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void permuteHelper(vector<int>& nums, vector<vector<int>>& res, int count, int size){
		if (count==size)
		{
			res.push_back(nums);
			return;
		}
		for (int i = count; i < size; ++i)
		{
			swap(nums[count], nums[i]);
			permuteHelper(nums,res,count+1,size);
			swap(nums[count],nums[i]);
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
     	  vector<vector<int>> res;
     	  int size = nums.size();
     	  permuteHelper(nums, res , 0, size);
     	  return res;
    }
};
