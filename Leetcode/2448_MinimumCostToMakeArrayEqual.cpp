#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<vector<int>> v;
        for(int i = 0; i< n; i++){
            v.push_back({nums[i], cost[i]});
        }
        sort(v.begin(), v.end(), [&](vector<int> a, vector<int> b){
            return a[0]<b[0];
        });
        vector<long> prefixCost(n);
        prefixCost[0] = v[0][1];
        for(int i = 1; i<n; i++){
            prefixCost[i] = prefixCost[i-1]+v[i][1];
        }
        long totalCost = 0;
        for(int i = 1; i<n; i++){
            totalCost += 1l  * v[i][1] * (v[i][0] - v[0][0]);
        }
        long answer = totalCost;
        for(int i = 1; i < n ; i++){
            int gap = v[i][0] - v[i-1][0];
            totalCost+= 1l * prefixCost[i-1] * gap;
            totalCost-= 1l * (prefixCost[n-1]-prefixCost[i-1])* gap;
            answer = min(answer, totalCost);
        }
        return answer;
    }
};