#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void dfs(vector<bool> &vis, vector<vector<int>> &adj, int node) {
    vis[node] = 1;
    for (auto neighbour : adj[node]) {
      if (!vis[neighbour]) {
        dfs(vis, adj, neighbour);
      }
    }
  }

  int removeStones(vector<vector<int>> &stones) {
    int n = stones.size();
    int cnt = 0;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
    vector<bool> vis(n, 0);
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        cnt++;
        dfs(vis, adj, i);
      }
    }
    return n - cnt;
  }
};

class SolutionUnionFind {
public:
  int removeStones(vector<vector<int>> &stones) {
    int n = stones.size();
    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]) {
          uf.unionNode(i, j);
        }
      }
    }
    return n - uf.totalConnectedComponents;
  }

private:
  class UnionFind {
  public:
    vector<int> parent;
    int totalConnectedComponents;

    UnionFind(int n) {
      // each node is its own parent
      parent.resize(n, -1);
      totalConnectedComponents = n;
    }
    int find(int node) {
      if (parent[node] == -1) {
        return node;
      } else
        return parent[node] = find(parent[node]);
    }
    void unionNode(int node1, int node2) {
      int p1 = find(node1);
      int p2 = find(node2);
      if (p1 == p2) {
        return;
      }
      parent[p1] = p2;
      totalConnectedComponents--;
    }
  };
};
