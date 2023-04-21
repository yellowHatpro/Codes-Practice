#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	void f(vector<int>& c, int target, vector<vector<int>>&res, int i, vector<int> curr){
		if (i==c.size()){
			if (target==0){
			res.push_back(curr);
			}
			return;
		}
		if (c[i]<=target) {
		curr.push_back(c[i]);
		f(c,target-c[i],res,i,curr);
		curr.pop_back();}
		f(c,target,res,i+1,curr);
	}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        f(candidates,target,res,0,{});
				return res;
    }
};