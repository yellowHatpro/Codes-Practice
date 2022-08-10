#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int f(vector<int> &dp, int n, int current, int cnt){
		if (current==n) return cnt;
		cnt += 


	}
    int reachNumber(int target) {
        vector<int> dp(target);
        return f(dp,target, 0, 0);
    }
};