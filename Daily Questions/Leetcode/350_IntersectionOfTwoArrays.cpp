#include <bits/stdc++.h>
using namespace std;
class BruteForceSolution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      vector<int> res;
      for(int i=0;i<nums1.size();i++){
          for(int j = 0;j<nums2.size();j++){
            if (nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                nums1[i] = -1;
                nums2[j] = -2;
            }
          }
      }
        return res;
    }
};

class Solution{
    public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
        unordered_map<int,int> m;
        vector<int> res;
        bool flag = false;
        if(nums1.size()>nums2.size()){
            flag = true;
        }
        if(flag){
            for (int i = 0; i < nums1.size(); i++)
        {
            m[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if(m.find(nums2[i]) != m.end() && m[nums2[i]]>0){
                res.push_back(nums2[i]);
                m[nums2[i]]--;
            }
        }
        }
        else{
            for (int i = 0; i < nums2.size(); i++)
        {
            m[nums2[i]]++;
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            if(m.find(nums1[i]) != m.end() && m[nums1[i]]>0){
                res.push_back(nums1[i]);
                m[nums1[i]]--;
            }
        }
        }
        
        return res;
    }
};