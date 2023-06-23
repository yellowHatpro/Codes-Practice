#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
      vector<vector<pair<int,int>>> adj(n);
      for (auto itr  : flights) {
        adj[itr[0]].push_back({itr[1],itr[2]});
      }  
      queue<pair<int,pair<int,int>>> q; //stop_number, src, distance
      q.push({0,{src,0}});
      vector<int> dist(n,1e9);
      dist[src] = 0;
      
      while (!q.empty()) {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;
        if (stops>K) continue;
        for (auto neighbourPair : adj[node]) {
          int neighbour = neighbourPair.first;
          int edgeWeight = neighbourPair.second;
          if (cost + edgeWeight < dist[neighbour] && stops <=K){
            dist[neighbour] = cost + edgeWeight;
            q.push({stops+1,{neighbour,dist[neighbour]}});
        }
        }
      }

      if (dist[dst]==1e9) return -1;
      return dist[dst];
  }
};
