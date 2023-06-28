#include <bits/stdc++.h>
#include <queue>
using namespace std;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<vector<pair<int, double>>> adj(n);
    for (int i = 0; i < edges.size(); i++) {
      auto itr = edges[i];
      double prob = succProb[i];
      adj[itr[0]].push_back({itr[1], prob});
      adj[itr[1]].push_back({itr[0], prob});
    }
    priority_queue<pair<double,int>> pq;
    vector<double> dist(n,0);
    dist[start] = 1;
    pq.push({0,start});
    while (!pq.empty()) {
      auto it = pq.top();
      pq.pop();
      double dis = it.first;
      int u = it.second;
      for (auto itr : adj[u]) {
        int v = itr.first;
        double wt = itr.second;
        if (dist[u]*wt>dist[v]){
          dist[v] = dist[u]*wt;
          pq.push({dist[v],v});
        }
      }
    }
    return dist[end];
  }
};
