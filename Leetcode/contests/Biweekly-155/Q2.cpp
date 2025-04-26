#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int MOD = 1e9 + 7;

private:
  void dfs(int n, vector<long long> &res,
           unordered_map<int, vector<vector<int>>> &adj, int node) {
    if (adj.find(node) == adj.end()) {
      return;
    }
    for (auto itr : adj[node]) {
      res[itr[0]] *= (itr[1]) % MOD;
      res[itr[0]] *= (res[node] % MOD);
      dfs(n, res, adj, itr[0]);
    }
    return;
  }

public:
  vector<int> baseUnitConversions(vector<vector<int>> &conversions) {
    int n = conversions.size();
    unordered_map<int, vector<vector<int>>> adj;
    for (auto v : conversions) {
      adj[v[0]].push_back({v[1], v[2]});
    }
    vector<long long> res(n + 1, 1);
    dfs(n, res, adj, 0);
    vector<int> ans;
    for (auto itr : res) {
      ans.push_back(itr % MOD);
    }
    return ans;
  }
};
