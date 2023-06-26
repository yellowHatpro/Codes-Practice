#include <bits/stdc++.h>
using namespace std;

class DSU{
  vector<int> rank, parent, size;
public:
  DSU(int n){
    rank.resize(n+1);
    parent.resize(n+1);
    size.resize(n+1);
    for (int i = 0 ; i <= n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int findUltimateParent(int node){
    if (node == parent[node]) return node;
    return parent[node] = findUltimateParent(parent[node]);
  }

  void unionByRank(int u, int v){
    int ultimateP_u = findUltimateParent(u);
    int ultimateP_v = findUltimateParent(v);
    if (ultimateP_u==ultimateP_v) return;
    if (rank[ultimateP_u]<rank[ultimateP_v]){
      parent[ultimateP_u] = ultimateP_v;
    } else if (rank[ultimateP_v]<rank[ultimateP_u]){
      parent[ultimateP_v] = ultimateP_u;
    } else {
      parent[ultimateP_v] = ultimateP_u;
      rank[ultimateP_u]++;
    }
  }

  void unionBySize(int u, int v){
    int ultimateP_u = findUltimateParent(u);
    int ultimateP_v = findUltimateParent(v);
    if (ultimateP_u == ultimateP_v) return;
    if (size[ultimateP_u]<size[ultimateP_v]){
      parent[ultimateP_u] = ultimateP_v;
      size[ultimateP_v] += size[ultimateP_u];
    } else {
      parent[ultimateP_v] = ultimateP_u;
      size[ultimateP_u] += size[ultimateP_v];
    }
  }
};
