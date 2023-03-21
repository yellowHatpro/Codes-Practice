#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0;
        int i = 0;
        int n = nums.size();
        while(i<n){
        	int j = i;
        	long long ze = 0;
        	while(j<n && nums[j++]==0){
        		ze++;
        	}
        	cnt+=(ze*(ze+1))/2;
        	i = j;
        }
        return cnt;
    }
};

class Solution_Good {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, numSubarray = 0;
        
        // Iterate over nums, if num = 0, it has 1 more zero-filled subarray
        // than the previous one, otherwise, it has 0 zero-filled subarray.
        for (auto num : nums) {
            if (num == 0)
                numSubarray++;
            else
                numSubarray = 0;
            ans += numSubarray;
        }
        
        return ans;
    }
};