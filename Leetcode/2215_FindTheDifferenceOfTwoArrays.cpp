#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> s2;
        vector<vector<int>> v;
        v.push_back({});
        v.push_back({});
        for (int i = 0; i < nums1.size(); ++i)
        {
        	s1.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); ++i)
        {
        	s2.insert(nums2[i]);
        }
        set<int>::iterator itr;
        for(itr = s1.begin();itr!= s1.end();itr++){
        	if (s2.find(*itr)==s2.end())
        	{
        		v[0].push_back(*itr);
        	}
        }
        for(itr = s2.begin();itr!= s2.end();itr++){
        	if (s1.find(*itr)==s1.end())
        	{
        		v[1].push_back(*itr);
        	}
        }
        return v;


    }
};