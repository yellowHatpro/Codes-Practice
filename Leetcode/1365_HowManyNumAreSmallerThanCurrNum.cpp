#include <bits/stdc++.h>
using namespace std;

//Bruteforce
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i; j < nums.size(); ++j)
            {
                if (nums[i]>nums[j]&&j!=i)
                {
                    v[i]++;
                }
            }
        }
        return v;
    }
};