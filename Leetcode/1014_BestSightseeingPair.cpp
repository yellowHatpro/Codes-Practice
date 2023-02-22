#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
    	int n = values.size();
        int ans = 0;
        int maxi = values[0] + 0; //values[i] + i
        for(int i = 1; i <n ;i++){
			ans = max(maxi+values[i]-i, ans); 
			maxi = max(maxi, values[i]+i);      	
        }
        return ans;
    }
};