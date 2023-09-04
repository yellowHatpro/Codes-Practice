#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int ans = -1;
    map<int,int> m;
  
    void dfs(vector<int>& adj, int currentNode, vector<int>&vis, vector<int>&pathVis){
    
    vis[currentNode] = 1;
    pathVis[currentNode] = 1;
    int neighbour = adj[currentNode];
    if (neighbour!=-1){
      if (!vis[neighbour]){
        m[neighbour] = m[currentNode] + 1;
        dfs(adj,neighbour,vis,pathVis);
      } else if (pathVis[neighbour]){
        int lengthOfCycle = m[currentNode] - m[neighbour] + 1;
        ans = max(ans, lengthOfCycle );
      } 
    }
        pathVis[currentNode] = 0;
  }

    int longestCycle(vector<int>& edges) {
      int n = edges.size();
      vector<int> vis(n+1);
      vector<int> pathVis(n+1);
      for(int i = 0 ; i < n; i++){
        if (!vis[i]){
          dfs(edges,i,vis,pathVis);
        }
      }
      return ans;
    }
};
