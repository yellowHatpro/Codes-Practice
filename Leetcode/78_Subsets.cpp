#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	vector<vector<int>> output;
	int n;

	void backtrack(int first, vector<int> v, vector<int> nums, int k){
		if (v.size()==k)
		{
			output.push_back(v);
			return;
		}
		for (int i = first; i < n; ++i)
		{
			v.push_back(nums[i]);
			backtrack(i+1,v, nums,k);
			v.pop_back();
		}
	}

	vector<vector<int>> subsets(vector<int>& nums) {
	 	n= nums.size();
	 	for (int i = 0; i < n+1; ++i)
	 	{	vector<int> v;
	 		backtrack(0,v,nums,i);
	 	}
	 	return output;
	 }
};

class SolutionRecursive {
public:
	vector<vector<int>> subs;

	void subsetsHelper(vector<int>& nums, int n, vector<int> v){
		if(n==nums.size()){
			return;
		}
		v.push_back(nums[n]);
		subs.push_back(v);
		subsetsHelper(nums,n+1,v);
		v.pop_back();
		subsetsHelper(nums,n+1,v);
	}
    vector<vector<int>> subsets(vector<int>& nums) {
    	subs.push_back({});
    	vector<int> v;
        subsetsHelper(nums,0,v);
        return subs;
    }
};

class SolutionOP {
public:

	void f(vector<vector<int>>&res, vector<int>&nums, int i, vector<int> v){
		if (i==nums.size()){
			res.push_back(v);
			return;
		}
		v.push_back(nums[i]);
		f(res,nums,i+1,v);
		v.pop_back();
		f(res,nums,i+1,v);
	}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        f(res,nums,i,{});
        return res;
    }
};


int main(){
	SolutionRecursive s;
	vector<int> nums = {1,2,3};
	vector<vector<int>> res= s.subsets(nums);

	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}