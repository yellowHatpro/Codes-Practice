#include <bits/stdc++.h>
#include <queue>
using namespace std;
class Solution {
private:
  vector<int> dijkstra(vector<vector<int>> adj) {
    vector<int> dist(adj.size(), 1e9);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, 0});
    while (!pq.empty()) {
      int dis = pq.top().first;
      int node = pq.top().second;
      pq.pop();
      for (auto neighbour : adj[node]) {
        if (dist[neighbour] > 1 + dis) {
          dist[neighbour] = 1 + dis;
          pq.push({dist[neighbour], neighbour});
        }
      }
    }
    return dist;
  }

public:
  int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience) {
    int n = patience.size();
    vector<vector<int>> adj(n);
    for (auto itr : edges) {
      adj[itr[0]].push_back(itr[1]);
      adj[itr[1]].push_back(itr[0]);
    }
    // Apply dijkstra algo to find the furthest node and its distance from node
    // 0
    vector<int> dist = dijkstra(adj);
    int ans = 0;
    for (int i = 1; i < n; i++) {
      int time = 2 * dist[i];
      int messageSent = time / patience[i];
      if (time % patience[i] == 0) {
        messageSent--;
      }
      int totalTimeForThisNode = messageSent * patience[i];
      ans = max(ans, totalTimeForThisNode + 2 * dist[i] + 1);
    }
    return ans;
  }
};
