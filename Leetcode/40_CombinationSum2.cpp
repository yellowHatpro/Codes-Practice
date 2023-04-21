#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	void f(vector<int>& nums, vector<vector<int>>& res, int i, vector<int> v){
		res.push_back(v);
		for (int j = i; j < nums.size(); ++j) {
			if (j!=i && nums[j]==nums[j-1]) continue;
			v.push_back(nums[j]);
			f(nums,res,j+1,v);
			v.pop_back();
		}
	}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        f(nums,res,0,{});
        return res;
    }
};