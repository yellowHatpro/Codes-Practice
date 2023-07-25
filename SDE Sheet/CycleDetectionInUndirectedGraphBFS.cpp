#include <bits/stdc++.h>
#include <queue>
using namespace std;

bool bfs(vector<vector<int>>&adj, int node, vector<int>&vis){
  queue<pair<int,int>> q;
  q.push({node,-1});
  vis[node] = 1;
  while(!q.empty()){
    int currNode = q.front().first;
    int parent = q.front().second;
    q.pop();
    for(auto neighbour: adj[currNode]){
      if (!vis[neighbour]){
        q.push({neighbour,currNode});
        vis[neighbour] = 1;
      } else {
        if (neighbour!=parent) return true;
      }
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
      if (bfs(adj,i,vis)) return "Yes";
    }
  }
  return "No";
}

