#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                            int firstPerson) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto itr : meetings) {
      adj[itr[0]].push_back({itr[1], itr[2]});
      adj[itr[1]].push_back({itr[0], itr[2]});
    }
    vector<int> peopleWithToken;
    vector<int> visited(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    pq.push({0, 0});
    pq.push({0, firstPerson});
    while (!pq.empty()) {
      int currenTime = pq.top().first;
      int person = pq.top().second;
      pq.pop();
      if (visited[person])
        continue;
      visited[person] = 1;
      for (auto neighbour : adj[person]) {
        if (!visited[neighbour.first] and neighbour.second >= currenTime) {
          pq.push({neighbour.second, neighbour.first});
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (visited[i])
        peopleWithToken.push_back(i);
    }
    return peopleWithToken;
  }
};
