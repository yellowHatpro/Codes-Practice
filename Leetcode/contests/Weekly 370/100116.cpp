#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findChampion(int n, vector<vector<int>> &edges) {
    vector<int> parent(n, -1);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
    for (int i = 0; i < edges.size(); i++) {
      parent[edges[i][1]] = parent[edges[i][0]];
    }

    for (auto itr : parent) {
      cout << itr << " ";
    }
    cout << endl;
    int ans = -1;
    for (int i = 0; i < parent.size(); i++) {
      if (ans != -1 && parent[i] == i)
        return -1;
      if (ans == -1 && parent[i] == i)
        ans = i;
    }
    return ans;
  }
};
