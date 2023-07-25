#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void topologicalSortDFS(vector<vector<int>>&adj, vector<int>&vis, int node,  vector<int>&ans){
vis[node] = 1;
for(auto neigh: adj[node]){
    if (!vis[neigh]){
      topologicalSortDFS(adj, vis, neigh, ans);
    }
  }
  ans.push_back(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
  vector<vector<int>> adj(v+1);
  vector<int> vis(v+1);
  vector<int> ans;
  for(auto itr: edges){
    adj[itr[0]].push_back(itr[1]);
  }
  for(int i = 0; i < v; i++){
   if (!vis[i])  topologicalSortDFS(adj,vis,i,ans);
  }
  reverse(ans.begin(),ans.end());
  return ans;
}
