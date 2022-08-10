#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lh;
        int n = height.size();
        vector<int> rh(n);
        int maxL = height[0];
        int maxR = height[n-1];
        int res = 0;

        for (int i = 0; i < n; ++i)
        {
        	maxL = max(maxL, height[i]);
        	lh.push_back(maxL);
        }
        for (int i = n-1; i >= 0; --i)
        {
        	maxR = max(maxR, height[i]);
        	rh[i]=maxR;
        }
        for (int i = 0; i < n; ++i)
        {
        	res+=min(rh[i],lh[i]) - height[i]; 
        }
        return res;
    }
};