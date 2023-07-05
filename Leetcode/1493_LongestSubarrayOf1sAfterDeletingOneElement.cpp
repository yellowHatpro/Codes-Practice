#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount = 0;
        int longestWindow = 0;
        int l = 0;
        
        for (int r = 0; r < nums.size(); r++) {
            zeroCount += (nums[r] == 0);
                          
            // Shrink the window until the zero counts come under the limit.
            while (zeroCount > 1) {
                zeroCount -= (nums[l] == 0);
                l++;
            }
              
            longestWindow = max(longestWindow, r - l);
        }

        return longestWindow;
    }
};
