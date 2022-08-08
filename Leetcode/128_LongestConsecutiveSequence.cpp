#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
        	m[nums[i]]++;
        }
        int maxi = 0;
        for (int i = 0; i < n; ++i)
        {
        	
        	if (!m[nums[i]-1]){
        		int current =1;
        		int crntEle = nums[i]+1;
        		while(m[crntEle]){
        			current++;
        			crntEle++;
        		}
        		maxi = max(maxi,current);
        	}
        	
        }
        return maxi;
    }
};