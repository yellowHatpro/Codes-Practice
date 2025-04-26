#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
  class UnionFind {
    vector<int> parent, rank, size;

  public:
    UnionFind(int n) {
      parent.resize(n, 0);
      rank.resize(n, 0);
      size.resize(n, 1);
      for (int i = 0; i < n; i++) {
        parent[i] = i;
      }
    }
    int find(int x) {
      if (parent[x] == x) {
        return x;
      }
      return parent[x] = find(parent[x]);
    }

    void unionByRank(int node1, int node2) {
      int p1 = find(node1), p2 = find(node2);
      if (p1 == p2) {
        return;
      }
      if (rank[p1] > rank[p2]) {
        parent[p2] = p1;
      } else if (rank[p1] < rank[p2]) {
        parent[p1] = p2;
      } else {
        parent[p1] = p2;
        rank[p2]++;
      }
    }
    void unionBySize(int node1, int node2) {
      int p1 = find(node1), p2 = find(node2);
      if (p1 == p2)
        return;
      if (size[p1] < size[p2]) {
        parent[p1] = p2;
        size[p2] += size[p1];
      } else {
        parent[p2] = p1;
        size[p1] += size[p2];
      }
    }
  };

public:
  vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit) {
    int n = nums.size();
    UnionFind uf(n);
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (abs(nums[i] - nums[j]) <= limit) {
          uf.unionByRank(i, j);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      mp[uf.find(i)].push_back(i);
    }
    for (auto &[parent, indices] : mp) {
      vector<int> vals;
      for (int idx : indices) {
        vals.push_back(nums[idx]);
      }
      sort(vals.begin(), vals.end());
      for (int j = 0; j < indices.size(); j++) {
        nums[indices[j]] = vals[j];
      }
    }
    return nums;
  }
};
