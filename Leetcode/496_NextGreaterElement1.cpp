#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> op;
        unordered_map<int,int> mp;
       for(int i=nums2.size()-1;i>=0;i--){
           while(!st.empty() && st.top()<=nums2[i])
               st.pop();
           mp[nums2[i]]=(st.empty())?-1:st.top();
           st.push(nums2[i]);
       }
        for(int i:nums1)
            op.push_back(mp[i]);
        return op;
    }
};