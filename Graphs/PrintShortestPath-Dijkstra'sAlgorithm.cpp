#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
      vector<vector<pair<int,int>>> adj(n+1);
      for (auto itr: edges){
        adj[itr[0]].push_back({itr[1], itr[2]});
        adj[itr[1]].push_back({itr[0], itr[2]});
    }
      vector<int> dist(n+1, 1e9), parent(n+1);
      for (int i = 1; i <= n; i++) {
        parent[i] = i;
      }
      dist[1] = 0;
      pq.push({0,1});
      while(!pq.empty()){
        auto it = pq.top();
        int node = it.second;
        int dis = it.first;
        pq.pop();
        for (auto neighbourPair : adj[node]) {
          int neighbour = neighbourPair.first;
          int edgeWeight = neighbourPair.second;
          if (dis+edgeWeight < dist[neighbour]){
            dist[neighbour] = dis+edgeWeight;
            pq.push({dist[neighbour], neighbour});
            parent[neighbour] = node;
          }
        }
    }
    if (dist[n]==1e9) return {-1};
    vector<int> path;
    int node = n;
    while(parent[node]!=node){
      path.push_back(node);
      node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;
    }
};
