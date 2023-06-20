#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:

  	bool dfs(int node, vector<int>& isSafe, vector<int> &vis, vector<int>&pathVis, vector<int> *adj){
  		vis[node]=1;
  		pathVis[node]=1;
  		for(auto neighbour:adj[node]){
  			if (!vis[neighbour]){
  				if (!dfs(neighbour, isSafe, vis, pathVis, adj)) {
  					isSafe[node] = 0;
  					return false;
  				};
  			} else if (pathVis[neighbour]) {
  				isSafe[node] = 0;
  				return false;
  			};
  		}
  		isSafe[node] = 1;
  		pathVis[node] = 0;
  		return true;
  	}

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> vis(V+1);
        vector<int> pathVis(V+1);
        vector<int> isSafe(V);
        vector<int> safeNodes;
        for (int i = 0; i < V; ++i)
        {
        	if (!vis[i])dfs(i,isSafe,vis,pathVis, adj);
        }
        for (int i = 0; i < isSafe.size(); ++i)
        {
        	if (isSafe[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};