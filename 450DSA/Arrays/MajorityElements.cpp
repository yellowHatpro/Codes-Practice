#include <bits/stdc++.h>
using namespace std;
//Codestudio
vector<int> countTheNumber(vector<int> &arr, int n, int k) {
	map<int, int> m;
	vector<int> v;
	int target = n/k;
	for(auto itr: arr){
		m[itr]++;
	}
	for(auto itr: m){
		if (itr.second>target) v.push_back(itr.first); 
	}
	return v;
}
//For n/3, using boyer mayor majority rule
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
         else if (nums[i]==element1) cnt1++;
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
      int majority3 = (int)(n/3) + 1;
      if (check_if_element1_valid>=majority3) v.push_back(element1);
      if (check_if_element2_valid>=majority3) v.push_back(element2);
      return v;
    }

    //for n/2
    class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int element = INT_MIN;
      int cnt=0;
      for (int i = 0; i < nums.size(); ++i)
      {
         if (cnt==0)
         {
            element = nums[i];
            cnt=1;
         }
         else if (element == nums[i]){
               cnt++;
            }
         else  cnt--;
      }
      return element;
        }
};