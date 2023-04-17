#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = *max_element(candies.begin(), candies.end());
        vector<bool> v;
        for (auto itr: candies){
            if (itr+extraCandies>=maxi){
                v.push_back(true);
            } else {
                v.push_back(false);
            }
        }
        return v;
    }
};