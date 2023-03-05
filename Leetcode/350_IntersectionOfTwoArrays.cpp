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
        map<int,int> m;
        vector<int> res;
        for(auto itr: nums1) m[itr]++;
        for(auto itr: nums2){
            if (m[itr]!=0){
                res.push_back(itr);
                m[itr]--;
            }
        }
        return res;
    }
};