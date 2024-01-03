#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    if (n == 1)
      return {0};
    if (n == 0)
      return {};
    vector<vector<int>> adj(n);
    queue<int> q;
    vector<int> indegree(n);
    for (auto itr : edges) {
      indegree[itr[0]]++;
      indegree[itr[1]]++;
      adj[itr[0]].push_back(itr[1]);
      adj[itr[1]].push_back(itr[0]);
    }
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 1)
        q.push(i);
    }
    while (n > 2) {
      int sz = q.size();
      n -= q.size();
      for (int i = 0; i < sz; i++) {
        int node = q.front();
        q.pop();
        for (auto itr : adj[node]) {
          indegree[itr]--;
          if (indegree[itr] == 1)
            q.push(itr);
        }
      }
    }
    vector<int> ans;
    while (!q.empty()) {
      int itr = q.front();
      q.pop();
      ans.push_back(itr);
    }
    return ans;
  }
};
