#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	int majority = nums[0];
    	int cnt=0;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if (nums[i]==majority)
    		{
    			cnt++;
    		}
    		else{
    				cnt--;
    			}
    		if (cnt==0)
    			{
    				majority = nums[i];
    				cnt = 1;
    			}
    	}
    	return majority;
        }
};
//This technique is called Moore's Voting Algorithm