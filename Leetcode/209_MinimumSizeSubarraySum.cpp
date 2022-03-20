//Sliding Window Problem

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int len = 0 ;
       int start=0;
       int sum = 0;
       int min_len=0;
       for (int i = 0; i < nums.size(); ++i)
       {
       	sum +=nums[i];
       	if (sum>=target)
       	{	len=i-start+1;
       		if (len<min_len)
       		{
       			min_len = len;
       		}
       		sum-=nums[start];
       		start++;
       	}
       	else{
       		start++;
       	}

       }
       return min_len;
    }
};