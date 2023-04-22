#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        int l = 0;
        int r = n-1;
        int i = n-1;
        while(i>=0){ //or l<=r
            if (abs(nums[l])>=abs(nums[r])){
                v[i--] = nums[l]*nums[l];
                l++;
            }
            else {
                v[i--] = nums[r]*nums[r];
                r--;
            }
        }
        return v;
    }
};

class SolutionNaive {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
            nums[i]*=nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};