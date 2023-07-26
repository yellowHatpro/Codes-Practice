#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>&adj, vector<int>& colors, int currNode){
  queue<int> q;
  q.push(currNode);
  colors[currNode] = 0;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto neighbour: adj[node]){
      if (colors[neighbour]!=-1){
        if (colors[neighbour]==colors[node]) return false;
      } else {
        colors[neighbour] = 1 - colors[node];
        q.push(neighbour);
      }
    }
  }
  return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
  int n = edges.size();
	vector<vector<int>> adj(n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if (edges[i][j]) adj[i].push_back(j);
    }
  }
  vector<int> colors(n,-1);
  for(int i = 0; i < n; i++){
    if (colors[i]==-1){
      if (!isBipartite(adj,colors,i)) return false;
    }
  }
  return true;
}
