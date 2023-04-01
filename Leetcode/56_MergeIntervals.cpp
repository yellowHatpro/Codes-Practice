#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (auto interval: intervals){
        	if (res.empty() || res.back()[1]< interval[0]) res.push_back(interval); //ex. [0,3] < [4,1]
        	else {
        		res.back()[1] = max(res.back()[1],interval[1]);
        	}
        }
        return res;
    }
};