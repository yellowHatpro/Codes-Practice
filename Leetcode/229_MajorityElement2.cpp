#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n = nums.size();
       vector<int> v;
       int done1=INT_MIN;
       int done2=INT_MIN;
      int max1=INT_MAX;
      int max2=INT_MAX;
      int cnt1 = 0;
      int cnt2 = 0;
      for (int i = 0; i < n; ++i)
      {
      	if (max1==nums[i])
      	{
      		cnt1++;
      	}
      	else if(max2==nums[i]){
      		cnt2++;
      		
      	}
      	else{
      		if (max1==INT_MAX)
      		{
      			max1 = nums[i];
      			cnt1++;
      		}
      		else if(max2==INT_MAX){
      			max2 = nums[i];
      			cnt2++;
      		}
      		else{
      			
      		
      		
      		cnt1--;
      			cnt2--;
      		}
      		if (cnt1==0&&max1!=INT_MAX)
      		{
      			max1 = nums[i];
      			cnt1++;
      		}
      		else if(cnt2==0&&max2!=INT_MAX){
      			max2 = nums[i];
      			cnt2++;
      		}
      	}
      		if (cnt1>n/3&&max1!=done1)
      		{
      			v.push_back(max1);
      			done1=max1;
      			cnt1 = 0;   			
      		}
      		else if (cnt2>n/3&&max2!=done2)
      		{
      			v.push_back(max2);
      			done2=max2;
      			cnt2=0;
      		}

      }
      return v;
    }
};