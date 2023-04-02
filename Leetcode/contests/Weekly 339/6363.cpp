#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        int maxElement = nums[0];
        map<int, int> m;
        int n = nums.size();
        set<int> s;
        for (int i = 0; i < n; ++i)
        {
        	s.insert(nums[i]);
        	m[nums[i]]++;
        	if (m[maxElement]<m[nums[i]]){
        		maxElement = nums[i];
        	}
        }
        while(s.size()!=0){
        	vector<int>v;
        	for(auto itr: m){
        		if (itr.second!=0){
        			v.push_back(itr.first);
        			m[itr.first]--;
        		}
        		if (itr.second==0){
        			s.erase(itr.first);
        		}
        	}
        if(!v.empty())	res.push_back(v);
        }
        return res;
    }
};