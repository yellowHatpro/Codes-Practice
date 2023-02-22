#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
    	int res = 0;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		int l = -1;
	    	int r = 0;
	    	int ln = -1;
	    	int rn = -1;
	    	int j = i;
	    	int cnt = 0;
            int p = 0;
    		while(j<nums.size()){
    			if (nums[j]<0){
    				if (ln == -1){
    					ln = j;
    				} 
					rn = j;
					cnt++;
    			} if (nums[j]>0){
                    p = 1;
                }
    			if (nums[j]==0){
    				break;
    			}
    			if (l == -1) l = j;
    			r = j;
    			j++;
    		}
            if (cnt==0 & p==0){
                continue;
            }
    		if (cnt%2==0) res = max(res, r-l+1);
    		else {
    			res = max({r - ln, rn-l, res });
    		}
    		i = j;
    	}
    	return res;
    }
};