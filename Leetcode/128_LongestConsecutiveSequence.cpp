#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int n = nums.size();
        int maxi = 0;
        for (auto itr: nums) {
            if (!s.count(itr-1)){
                int current =1;
                int crntEle = itr;
                while(s.count(crntEle+1)){
                    current++;
                    crntEle++;
                }
                maxi = max(maxi,current);
            }
        }
        return maxi;
    }
};