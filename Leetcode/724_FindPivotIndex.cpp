#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum =accumulate(nums.begin(),nums.end(),0);
        int curr = 0,i = 0;
        for(auto itr: nums){
            curr+=itr;
            if ((curr-itr)==(sum-curr)){
                return i;
            } 
            i++;
        }
        return -1;
    }
};