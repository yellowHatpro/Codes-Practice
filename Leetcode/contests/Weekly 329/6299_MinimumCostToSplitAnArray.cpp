#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        long long gans=100000000000000;
        for(int maxcnt = 1;maxcnt=n;maxcnt++){
            long long curans =0;
            for (int i = 0; i < n; ++i)
            {
                set<int> s;
                while(i<n and s.size()<maxcnt){
                    s.insert(nums[i]);
                    i++;
                }        
                curans+=k+(int(s.size()));
            }    
            if (curans<gans)
            {
                gans=curans;
            }
        }
        return (int)gans;
    }
};