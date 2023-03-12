//Upsolved
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
    	map<int, int> m;
        int cnt = 0;
        m[cnt]++;
        int res = 0;
        for(int i = 0; i<nums.size();i++){
        	cnt^=nums[i];
        	m[cnt]++;
        	res+=m[cnt]-1;
        }
        return res;
    }
};