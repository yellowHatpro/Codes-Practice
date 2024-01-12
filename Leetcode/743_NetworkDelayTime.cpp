#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto itr : times) {
      adj[itr[0]].push_back({itr[1], itr[2]});
    }
    vector<int> dist(n, INT_MAX);
    dist[0] = 0; // Since 1-based indexing,not relevant to algo
    dist[k] = 0;
    int ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, k});
    while (!pq.empty()) {
      int wt = pq.top().first;
      int u = pq.top().second;
      pq.pop();
      for (auto neighbour : adj[u]) {
        if (neighbour.second + wt < dist[neighbour.first]) {
          dist[neighbour.first] = neighbour.second + wt;
          pq.push({dist[neighbour.first], neighbour.first});
        }
      }
    }
    for (auto itr : dist) {
      if (itr == INT_MAX)
        return -1;
    }
    for (auto itr : dist) {
      ans = max(itr, ans);
    }
    return ans;
  }
};
