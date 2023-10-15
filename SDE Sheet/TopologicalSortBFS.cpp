#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
  vector<vector<int>> adj(v + 1);
  vector<int> indegree(v + 1);
  vector<int> ans;
  for (auto itr : edges) {
    adj[itr[0]].push_back(itr[1]);
    indegree[itr[1]]++;
  }
  queue<int> q;
  for (int i = 0; i < v; i++) {
    if (indegree[i] == 0)
      q.push(i);
  }
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for (auto neighbour : adj[node]) {
      indegree[neighbour]--;
      if (indegree[neighbour] == 0)
        q.push(neighbour);
    }
  }
  return ans;
}
