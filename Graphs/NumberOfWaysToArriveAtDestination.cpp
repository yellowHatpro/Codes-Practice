#include <bits/stdc++.h>
#include <queue>
using namespace std;
class Solution {
  public:
    int mod =(int) 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto itr  : roads) {
          adj[itr[0]].push_back({itr[1], itr[2]});
          adj[itr[1]].push_back({itr[0], itr[2]});
        }
        vector<long long> dist(n,1e15), paths(n,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
      pq.push({0,0});
      dist[0] = 0;
      paths[0] = 1;
      while (!pq.empty()) {
        auto itr = pq.top();
        pq.pop();
        int node = itr.second;
        int dis = itr.first;
        for (auto neighbourPair : adj[node]) {
          int neighbour = neighbourPair.first;
          int edgeWeight = neighbourPair.second;
          if ((long long)edgeWeight + dis < dist[neighbour]){
            dist[neighbour] = (long long) edgeWeight + dis;
            paths[neighbour] = (long long) paths[node];  
            pq.push({edgeWeight+dis,neighbour});
        } else if (dis + edgeWeight == dist[neighbour]) {
            paths[neighbour] = (paths[neighbour] + paths[node])%mod;
        }
        }   
      }
      return paths[n-1]%mod;
    }
};
