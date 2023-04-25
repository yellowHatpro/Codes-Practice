#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int l = 0;
        int r = n-1;
        while(r>l){
            ans = max(ans, (r-l)*(min(height[l],height[r])));
            (height[l]>height[r]) ? r-- : l++;
        }
        return ans;
    }
};
//TODO : Try it with monotone stack