#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        double res = nums[0];
        long long totalSum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
        	totalSum+=nums[i];
        	res = max(res,ceil(totalSum/(i+1.0)));
        }
        return (int)res;
    }
};