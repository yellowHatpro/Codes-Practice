#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        vector<int> v;
        for (int i = 0; i < nums1.size(); ++i)
        {
        	s.insert(nums1[i]);
        }
        set<int>:: iterator it;
        for(it = s.begin(); it!=s.end(); it++){
        	if (std::count(nums2.begin(), nums2.end(),*it))
        	{
        		v.push_back(*it);
        	}
        }
        return v;
    }
};