#include <bits/stdc++.h>
using namespace std;

// In directed graphs, we use topological sort for BFS and vis and path vis for DFS

bool dfs(vector<vector<int>>&adj, int node, vector<int>&vis, vector<int>&pathVis){
  vis[node] = 1;
  pathVis[node] = 1;
  for(auto neighbour: adj[node]){
    if (!vis[neighbour]){
      if (dfs(adj, neighbour, vis,pathVis)) return true;
    } else {
      if (pathVis[neighbour]) return true;
    }
  }
  pathVis[node] = 0;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<int> vis(n+1);
  vector<int> pathVis(n+1);
  vector<vector<int>> adj(n+1);
  for(auto itr: edges){
    adj[itr.first].push_back(itr.second);
  }
  for(int i = 1; i <= n; i++){
    if (!vis[i]){
      if (dfs(adj,i,vis,pathVis)) return 1;
    }
  }
  return 0;
}
