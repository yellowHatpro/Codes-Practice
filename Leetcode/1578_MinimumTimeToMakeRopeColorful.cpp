#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cnt = 0;
        for (int i = 1; i < neededTime.size(); ++i)
        {
        	if(colors[i]==colors[i-1]) {
        		int m = min(neededTime[i],neededTime[i-1]);
        		cnt+=m;
        		neededTime[i] = max(neededTime[i],neededTime[i-1]);
        	}
        }
        return cnt;
    }
};