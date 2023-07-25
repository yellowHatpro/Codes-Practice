#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj, int node, int parent, vector<int> &vis){
  vis[node] = 1;
  for(auto neighbour: adj[node]){
    if (!vis[neighbour]){
      if (dfs(adj,neighbour,node,vis)) return true;
    } else {
      if (parent!=neighbour) return true;
    }
  }
  return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m) {
  vector<int> vis(n+1);
  vector<vector<int>> adj(n+1);
  for(auto itr: edges){
    adj[itr[0]].push_back(itr[1]);
    adj[itr[1]].push_back(itr[0]);
  }
  for(int i = 0; i < n; i++){
    if (!vis[i]){
      if (dfs(adj,i,-1,vis)) return "Yes";
    }
  }
  return "No";
}

