#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    void dfs(vector<int>&res, vector<int>&vis, vector<int> adj[], int i){
      vis[i] = 1;
      res.push_back(i);
      for(auto neighbour: adj[i]){
        if (!vis[neighbour]){
          dfs(res,vis,adj,neighbour);
      }
    }
  }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
      vector<int> res;
      vector<int> vis(V+1);
      dfs(res,vis,adj,0);
      return res;
  }
};
