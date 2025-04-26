#include <bits/stdc++.h>
using namespace std;
class SolutionA {
public:
  int trap(vector<int> &height) {
    vector<int> lh;
    int n = height.size();
    vector<int> rh(n);
    int maxL = height[0];
    int maxR = height[n - 1];
    int res = 0;

    for (int i = 0; i < n; ++i) {
      maxL = max(maxL, height[i]);
      lh.push_back(maxL);
    }
    for (int i = n - 1; i >= 0; --i) {
      maxR = max(maxR, height[i]);
      rh[i] = maxR;
    }
    for (int i = 0; i < n; ++i) {
      res += min(rh[i], lh[i]) - height[i];
    }
    return res;
  }
};

/*
Intution for the below solution:
Looking carefully, we can see that only the shorter side will tell how much
water can I store in a particular index. So, in the below approach I am
guaranteeing that I am iterating from the smaller side. If I move from l to r,
that means left has a smaller wall/boundary than the right wall/boundary. That
means, how much water I will fill, will depend on the left boundary.
*/

class Solution {
public:
  int trap(vector<int> &heights) {
    int l = 0;
    int r = heights.size() - 1;
    int lMax = heights[l];
    int rMax = heights[r];
    int totalWater = 0;
    while (l < r) {
      if (heights[l] <= heights[r]) {
        if (heights[l] < lMax) {
          totalWater += (lMax - heights[l]);
        }
        lMax = max(lMax, heights[l]);
        l++;
      } else {
        if (heights[r] < rMax) {
          totalWater += (rMax - heights[r]);
        }
        rMax = max(rMax, heights[r]);
        r--;
      }
    }
    return totalWater;
  }
};
