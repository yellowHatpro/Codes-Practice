#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution{
  public:
  vector<int> dijkstra(int v, vector<vector<int>> adj[], int st){
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  vector<int> dist(v, 0);
  for(int i = 0; i<v; i++) dist[i] = 1e9;
  dist[st] = 0;
  pq.push({0,st}); // in pair, first is weight, second is the node
  while (!pq.empty()) {
    int dis = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    for (auto neighbourPair : adj[node]) {
      int edgeWeight = neighbourPair[1];
      int neighbour = neighbourPair[0];
      if (dis+edgeWeight < dist[neighbour]){
        dist[neighbour] = dis+edgeWeight;
        pq.push({dist[neighbour], neighbour});
      }
    } 
  }   
  return dist;
}
};
