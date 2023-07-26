#include <bits/stdc++.h>
using namespace std;


bool isBipartite(vector<vector<int>>&adj, int col, vector<int>&colors, int node){
  colors[node] = col;
  for(auto neighbour: adj[node]){
    if (colors[neighbour]==-1){
      if (!isBipartite(adj, !col, colors, neighbour)) return false;
    } else {
      if (colors[neighbour]==colors[node]) return false;
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
      if (!isBipartite(adj,0,colors,i)) return false;
    }
  }
  return true;
}
