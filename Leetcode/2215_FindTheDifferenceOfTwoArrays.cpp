#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        vector<vector<int>> v(2);
        for(auto itr: s1){
            if (s2.count(itr)==0){
                v[0].push_back(itr);
            }
        }
        for (auto itr: s2){
            if (s1.count(itr)==0){
                v[1].push_back(itr);
            }
        }
        return v;
    }
};