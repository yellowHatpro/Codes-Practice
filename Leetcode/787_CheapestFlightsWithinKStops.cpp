#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto flight : flights) {
      adj[flight[0]].push_back({flight[1], flight[2]});
    }
    queue<pair<int, pair<int, int>>> q;
    vector<int> distance(n, 1e9);
    distance[src] = 0;
    q.push({src, {0, 0}});
    int cnt = 0;
    while (!q.empty()) {
      int node = q.front().first;
      int step = q.front().second.first;
      int dist = q.front().second.second;
      q.pop();
      for (auto neighbour : adj[node]) {
        int v = neighbour.first;
        int w = neighbour.second;
        if (w + dist < distance[v] and step <= k) {
          distance[v] = w + dist;
          q.push({v, {step + 1, distance[v]}});
        }
      }
    }
    if (distance[dst] == 1e9) {
      return -1;
    }
    return distance[dst];
  }
};
