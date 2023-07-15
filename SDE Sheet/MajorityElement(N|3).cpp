#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int n = nums.size();
      int cnt1 = 0;
      int cnt2 = 0;
      int major1 = INT_MIN, major2 = INT_MIN;
      for(int i = 0; i < n; i++){
        if (cnt1==0 && nums[i]!=major2) major1 = nums[i];
        else if (cnt2==0 && nums[i]!=major1) major2 = nums[i];

        if (nums[i]==major1 && nums[i]!=major2) cnt1++;
        else if (nums[i]==major2 && nums[i]!=major1) cnt2++;
        else {
          cnt1--;
          cnt2--;
      }
      }
      
      vector<int> v;
      cnt1 = 0;
      cnt2 = 0;
      for (auto itr: nums){
        if (itr==major1) cnt1++;
        if (itr==major2) cnt2++;
    }
      if (cnt1>n/3) v.push_back(major1);
      if (cnt2>n/3) v.push_back(major2);
      sort(v.begin(), v.end());
      return v;
    }
};
