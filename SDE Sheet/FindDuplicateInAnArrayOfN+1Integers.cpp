#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int slow = nums[0];
      int fast = nums[nums[0]];
      while(fast!=slow){
      slow = nums[slow];
      fast = nums[nums[fast]];
      if (slow==fast) break;
    }
    fast = 0;
    while (fast!=slow) {
      fast = nums[fast];
      slow = nums[slow];
    }
    return slow;
    }
};
