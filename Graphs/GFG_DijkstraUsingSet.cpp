#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int v, vector<vector<int>> adj[], int st){
    set<pair<int,int>> nodes;
    nodes.insert({0,st});
    vector<int> dist(v,1e9);
    dist[st] = 0;
    while(!nodes.empty()){
      auto itr = *(nodes.begin());
      int node = itr.second;
      int dis = itr.first;
      nodes.erase(itr);
      for (auto neighbourPair : adj[node]) {
        int edgeWeight = neighbourPair[1];
        int neighbour = neighbourPair[0];
        if (dis + edgeWeight < dist[neighbour]){
          //we can erase the node if it existed
          if (dist[neighbour]!=1e9){
            nodes.erase({dist[neighbour],neighbour});
          } 
          dist[neighbour] = dis+edgeWeight;
          nodes.insert({dist[neighbour], neighbour});
        }
      }
    }
    return dist;
  }
};
