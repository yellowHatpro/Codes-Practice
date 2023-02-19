#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> mp;
        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < n; ++i)
        {
        	mp[nums1[i][0]] = nums1[i][1]; 
        }
        for (int i = 0; i < m; ++i)
        {
        	if (mp[nums2[i][0]]!=0){
        		mp[nums2[i][0]]+=nums2[i][0];
        	} else {        	
        		mp[nums2[i][0]] = nums2[i][1];
        	}
        }
        vector<vector<int>> res;
        for (auto itr: mp){
        	vector<int> r;
        	r.push_back(itr.first);
        	r.push_back(itr.second);
        	res.push_back(r);
        }
        return res;
    }
};