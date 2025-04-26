#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
  class UnionFind {
  public:
    vector<int> parent;
    int totalConnectedComponents;

    UnionFind(int n) {
      parent.resize(n, -1);
      totalConnectedComponents = n;
    }

    int find(int node) {
      if (parent[node] == -1) {
        return node;
      }
      return parent[node] = find(parent[node]);
    }
    void unionNodes(int node1, int node2) {
      int p1 = find(node1);
      int p2 = find(node2);
      if (p1 == p2) {
        return;
      } else {
        parent[p1] = p2;
        totalConnectedComponents--;
      }
    }
  };

public:
  int numberOfComponents(vector<vector<int>> &properties, int k) {
    int n = properties.size();
    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        vector<int> a = properties[i];
        vector<int> b = properties[j];
        int m = a.size();
        int cnt = 0;
        unordered_map<int, bool> mm;
        for (int x = 0; x < m; x++) {
          mm[a[x]] = true;
        }
        for (int x = 0; x < m; x++) {
          if (mm[b[x]]) {
            mm[b[x]] = false;
            cnt++;
          }
        }
        if (cnt >= k) {
          uf.unionNodes(i, j);
        }
      }
    }
    return uf.totalConnectedComponents;
  }
};
