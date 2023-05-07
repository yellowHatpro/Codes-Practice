#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int n = nums.size();
      vector<int> v;
      int element1 = INT_MIN, element2 = INT_MIN, cnt1 = 0, cnt2 = 0;
      for (int i = 0; i < n; ++i)
      {
         if (cnt1==0 && nums[i]!=element2){
            element1 = nums[i];
            cnt1 = 1;
         } else if (cnt2==0 && nums[i]!=element1){
            element2 = nums[i];
            cnt2 = 1;
         }
         if (nums[i]==element1) cnt1++;
         else if (nums[i]==element2) cnt2++;
         else {
            cnt1--;
            cnt2--;
         }
      }
      int check_if_element1_valid = 0, check_if_element2_valid = 0;
      for (int i = 0; i < n; ++i)
      {
         if (element1==nums[i]) check_if_element1_valid++;
         else if (element2 == nums[i]) check_if_element2_valid++;
      }
      int majority3 = (n/3);
      if (check_if_element1_valid>majority3) v.push_back(element1);
      if (check_if_element2_valid>majority3) v.push_back(element2);
      return v;
    }
};