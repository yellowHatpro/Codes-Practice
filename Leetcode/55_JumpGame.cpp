#include <bits/stdc++.h>
using namespace std;

class SolutionGreedy {
public:
    bool canJump(vector<int>& nums) {
    	int n = nums.size();
        int jump = n-1;
        for (int i = n-2; i >=0; i--)
        {
        	if (i+nums[i]>=jump){
        		jump = i;
        	}
        }
        return jump==0;
    }
};