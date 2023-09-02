#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
      int n = height.size();
      int maxL = 0;
      int maxR = 0;
      int l = 0;
      int r = n-1;
      int ans=0;
      while(l<=r){
        if (height[l]<=height[r]){
          if (height[l]>=maxL) maxL = height[l];
          else ans+=(maxL-height[l]);
          l++;
        } else {
          if (height[r]>=maxR) maxR = height[r];
          else ans+=(maxR-height[r]);
          r--;
        }
      }
      return ans;
    }
};
