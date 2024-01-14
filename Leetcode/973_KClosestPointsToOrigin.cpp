#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long dist(int x, int y) { return x * x + y * y; }

  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    priority_queue<pair<long long, vector<int>>> pq;
    for (int i = 0; i < k; i++) {
      auto len = (dist(points[i][0], points[i][1]));
      pq.push({len, points[i]});
    }
    for (int i = k; i < points.size(); i++) {
      if (dist(points[i][0], points[i][1]) < pq.top().first) {
        pq.pop();
        auto len = (dist(points[i][0], points[i][1]));
        pq.push({len, points[i]});
      }
    }
    vector<vector<int>> res;
    while (!pq.empty()) {
      res.push_back(pq.top().second);
      pq.pop();
    }
    return res;
  }
};
