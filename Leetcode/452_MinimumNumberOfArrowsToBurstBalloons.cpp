#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end(),
         [](vector<int> a, vector<int> b) { return a[1] < b[1]; });
    int ans = 1;
    int currentReach = points[0][1];
    for (int i = 1; i < points.size(); i++) {
      if (points[i][0] > currentReach) {
        ans++;
        currentReach = points[i][1];
      }
    }
    return ans;
  }
};
