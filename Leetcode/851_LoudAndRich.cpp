#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
    int n = quiet.size();
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    vector<int> ans(n, INT_MAX);
    queue<int> q;
    for (auto itr : richer) {
      adj[itr[0]].push_back(itr[1]);
      indegree[itr[1]]++;
    }
    for (int i = 0; i < n; i++) {
      ans[i] = i;
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto itr : adj[node]) {
        if (ans[itr] == INT_MAX or quiet[ans[itr]] > quiet[ans[node]]) {
          ans[itr] = ans[node];
        }
        indegree[itr]--;
        if (indegree[itr] == 0) {
          q.push(itr);
        }
      }
    }
    return ans;
  }
};
