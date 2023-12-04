#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int getSum(int node, vector<vector<int>> &adj, vector<int> &vis,
             map<int, int> &sumM, vector<int> &values) {
    vis[node] = 1;
    int sum = 0;
    for (auto child : adj[node]) {
      sum = getSum(child, adj, vis, sumM);
    }
    sumM[node] = sum;
  }

  long long maximumScoreAfterOperations(vector<vector<int>> &edges,
                                        vector<int> &values) {
    int ans1 = 0;
    for (int i = 1; i < values.size(); i++) {
      ans1 += values[i];
    }
    int ans2 = 0;
    vector<vector<int>> adj(values.size());
    for (auto itr : edges) {
      adj[itr[0]].push_back(itr[1]);
    }
    map<int, int> sumM;
    vector<int> vis(values.size(), -1);
    getSum(0, adj, vis, sumM, values);
  }
};
