#include <bits/stdc++.h>
#include <climits>
using namespace std;

//Single source shorted path
// For directed graphs : but we can convert undirected graph to directed
// Works for negetive weights
// Can identify negetive cycles

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
  vector<int> dist(n+1,1000000000);
  dist[src] = 0;
  for(int i = 0; i <n-1; i++){
    for(auto edge: edges){
      int u = edge[0];
      int v = edge[1];
      int wt = edge[2];
      if (dist[u]!=1000000000 && dist[u]+wt<dist[v]) dist[v] = dist[u]+wt;
    }
  }
  return dist[dest];
}
