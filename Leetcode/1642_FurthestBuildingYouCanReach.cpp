#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    int n = heights.size();
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    for (int i = 0; i < n - 1; i++) {
      int req = heights[i + 1] - heights[i];
      if (req > 0) {
        // means I can still use ladders
        if (pq.size() < ladders) {
          pq.push(req);
        } else {
          if (pq.empty() or pq.top() >= req) {
            // this condition means if current diff is small, that means I don't
            // need to waste my ladder here. Thus, ladder was correctly used
            // before, and I should use bricks here.
            bricks -= req;
          } else {
            // current diff is more, means I would need the ladder I used before
            // here, and I should have used bricks before, thus use ladder here,
            // and remove pq.top() bricks
            bricks -= pq.top();
            pq.pop();
            pq.push(req);
          }
          if (bricks < 0)
            return i;
        }
      }
    }
    return n - 1;
  }
};
