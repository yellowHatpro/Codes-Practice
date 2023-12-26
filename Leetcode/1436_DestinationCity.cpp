#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string destCity(vector<vector<string>> &paths) {
    map<string, vector<string>> adj;
    for (auto itr : paths) {
      adj[itr[0]].push_back(itr[1]);
      if (adj.find(itr[1]) == adj.end())
        adj[itr[1]] = {};
    }
    for (auto itr : adj) {
      if (itr.second.size() == 0)
        return itr.first;
    }
    return "";
  }
};
