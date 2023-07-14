#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    vector<int> bfs(vector<int> &res, vector<int>& vis, vector<int> adj[], int i){
      queue<int> q;
      q.push(i);
      vis[i] = 1;
      while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);
        for(auto neighbour: adj[node]){
          if (!vis[neighbour]){
            q.push(neighbour);
            vis[neighbour] = 1; 
        }
      }
    }
    return res;
  }

    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
      vector<int> res;
      vector<int> vis(V+1);
      return bfs(res,vis,adj,0);
  }
};
