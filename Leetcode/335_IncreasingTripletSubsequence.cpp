#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      int a = INT_MAX, b = INT_MAX;
      for(auto num: nums){
        if (num<=a) a = num;
        else if (num<=b) b = num;
        else return true;
      }
      return false;
    }
};
