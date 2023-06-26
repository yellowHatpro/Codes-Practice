#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int>parent, size;
    
  int findParent(int node){
    if (node == parent[node]) return node;
    return parent[node] = findParent(parent[node]);
  }
  
  void unionBySize(int u, int v){
    int upu = findParent(u);
    int upv = findParent(v);
    if (size[upu]<size[upv]){
      parent[upu] = upv;
      size[upv]+=size[upu];
    } else {
      parent[upv] = upu;
      size[upu]+=size[upv];
    }
  }


  int numProvinces(vector<vector<int>> adj, int V) {
        parent.resize(V+1);
        size.resize(V+1,1);
        for (int i = 0; i < V; i++) {
          parent[i] = i;
        }
        int ans = 0;
        for (int i = 0; i < V; i++) {
          for (int j = 0; j < V; j++) {
            if (adj[i][j]==1){
            unionBySize(i, j);
        }
          }      
    }  
    for (int i = 0; i < V; i++) {
      if (parent[i]==i) ans++;
    }
    return ans;
  }
};
