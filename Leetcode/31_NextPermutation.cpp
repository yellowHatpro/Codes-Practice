#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size()==1){
            return;
        }
        if (nums.size()==2) {swap(nums[0],nums[1]);
                           return;}
    	int index = -1;
    	int just_bigger_index = -1;
        for (int i = nums.size()-2; i>=0; i--)
        {
        	if (nums[i]<nums[i+1])
        	{
        		index=i;
                break;
        	}
        }
          if (index==-1)
        {
        	reverse(nums.begin(),nums.end());
              return;
        }
        for (int i = nums.size()-1; i >index; i--)
        {
        	if (nums[i]>nums[index])
        	{
        		just_bigger_index = i;
                break;
        	}
        }
        swap(nums[index],nums[just_bigger_index]);

           reverse(nums.begin() + index + 1, nums.end());
    }
};

class Attempt2{
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int smallFromRight = -1;
        //Find the first index (i-1) where nums[i-1]<nums[i]..
        for(int i = n-1;i>0;i--){
            if (nums[i-1]<nums[i]){
                smallFromRight = i-1;
                break;
            }
        }
        // smallFromRight means array is reverse sorted, so next permutation will be its sorted counterpart
            if (smallFromRight==-1){
                reverse(nums.begin(),nums.end());
                return;
            }
            //Find the JUST LARGER number from nums[smallFromRight]
            int justLargerThanSmallFromRight = -1;
            for(int i = smallFromRight+1;i<n;i++){
                if (nums[i]<=nums[smallFromRight]){
                    break;
                }
                justLargerThanSmallFromRight = i;
            }
            //Swap these two numbers
            swap(nums[smallFromRight],nums[justLargerThanSmallFromRight]);
            //Reverse the array from the index where we initially got the smallFromRight..
            reverse(nums.begin()+smallFromRight+1,nums.end());
            return;
    }
};