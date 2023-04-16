#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int n = nums.size();
        int m = divisors.size();
        pair<int,int> maxi = {INT_MAX, 0};
        for (int i = 0; i < m; ++i)
        {	
        	int cur = 0;
        	for (int j = 0; j < n; ++j)
        	{
        		if (nums[j]%divisors[i]==0) cur++;
        	}
        	if (cur>=maxi.second){
        		if (cur==maxi.second) maxi.first = min(maxi.first, divisors[i]); else maxi.first = divisors[i];
        		maxi.second = cur;
        	}
        }
        return maxi.first;
    }
};	