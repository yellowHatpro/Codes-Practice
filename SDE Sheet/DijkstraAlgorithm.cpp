#include <bits/stdc++.h>
using namespace std;

//Shortest path single source weighted graphs
//Works for both directed and undirected graphs
//Not for negetive weights 

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<vector<pair<int,int>>> adj(vertices);
    for(auto edge: vec){
      adj[edge[0]].push_back({edge[1],edge[2]});
      adj[edge[1]].push_back({edge[0],edge[2]});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<int> dist(vertices,INT_MAX);
    dist[source] = 0;
    pq.push({0,source});
    while(!pq.empty()){
      int wt = pq.top().first;
      int u = pq.top().second;
      pq.pop();
      for(auto neighbour: adj[u]){
        int v = neighbour.first;
        int edgeWt = neighbour.second;
        if (edgeWt+wt < dist[v]){
          dist[v] = edgeWt+wt;
          pq.push({dist[v],v});
      }
    }
  }
  return dist;
}

