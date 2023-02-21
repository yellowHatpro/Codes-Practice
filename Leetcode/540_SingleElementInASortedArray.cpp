#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x = nums[0];
        for (int i =1; i<nums.size();i++){
            x^=nums[i];
        }
        return x;
    }
};