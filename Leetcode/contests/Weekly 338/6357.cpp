#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> res;
        long long nsum = accumulate(nums.begin(), nums.end(),0);
        long long n = nums.size();
        int m = queries.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < m; ++i)
        {
        	int lower = *lower_bound(nums.begin(), nums.end(), queries[i]);
        	int addsum = 0;
        	if (lower<m){
        		addsum = accumulate(nums.begin() + lower, nums.end(),0);
        		addsum -=((m-lower+1)*queries[i]);
        	}
        	res.push_back((nsum-(n*queries[i]))+2*addsum);
        }
        return res;
    }
};

