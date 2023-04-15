#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int del = 0;
        int n = nums.size();
        int gap = 0;
        for (int i = 0; i < n-1; ++i) {
        	gap = i - del;
        	if (nums[i]==nums[i+1] && gap%2==0){
        		del++;
        	}
        }
        if ((n-del)%2) del++;
        return del;
    }
};