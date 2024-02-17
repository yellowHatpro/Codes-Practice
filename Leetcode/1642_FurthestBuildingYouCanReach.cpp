#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    for (int i = 1; i < heights.size(); i++) {
      if (heights[i] - heights[i - 1] <= 0) {
        ans++;
        continue;
      }
      pq.push(heights[i] - heights[i - 1]);
      if (pq.size() > ladders) {
        if (bricks - pq.top() >= 0) {
          bricks -= pq.top();
          pq.pop();
          ans++;
        } else {
          return ans;
        }
      } else {
        ans++;
      }
    }
    return ans;
  }
};
