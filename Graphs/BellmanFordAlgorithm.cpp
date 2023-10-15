#include <bits/stdc++.h>
using namespace std;

// For Directed Graphs
// Helps detect negative cycles
// For undirected graphs, convert them to directed graphs

class Solution {
public:
  /*  Function to implement Bellman Ford
   *   edges: vector of vectors which represents the graph
   *   S: source vertex to start traversing graph with
   *   V: number of vertices
   */
  vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S) {
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for (int i = 0; i < V - 1; i++) {
      for (auto itr : edges) {
        int u = itr[0];
        int v = itr[1];
        int wt = itr[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
          dist[v] = dist[u] + wt;
        }
      }
    }
    for (auto itr : edges) {
      int u = itr[0];
      int v = itr[1];
      int wt = itr[2];
      if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
        return {-1};
      }
    }
    return dist;
  }
};
