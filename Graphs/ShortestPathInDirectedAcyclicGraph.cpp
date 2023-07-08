#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  	void dfs(vector<int> &vis, vector<vector<pair<int,int>>> &adj, int node, stack<int> &s){
  		vis[node] = 1;
  		for(auto neighbour: adj[node]){
  			if (!vis[neighbour.first]){
  				dfs(vis,adj,neighbour.first,s);
  			}
  		}
  		s.push(node);
  	}

     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        //n nodes
        //m edges
        //toposort and store nodes in vector<pair>
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> vis(n);
        stack<int> s;
        for (int i = 0; i < m; ++i)
        {
        	adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        for (int i = 0; i < n; ++i)
        {
        	if (!vis[i]){
        		dfs(vis,adj,i,s);
        	}
        }
        vector<int> dist(n);
        for(int i=0;i<n;i++) dist[i] = 1e9;
        dist[0] = 0;
        while(!s.empty()){
        	int node = s.top();
        	s.pop();
        	for(auto neighbour: adj[node]){
        		if (neighbour.second+dist[node] < dist[neighbour.first]){
        			dist[neighbour.first] = neighbour.second + dist[node];
        		}
        	}
        }
        for(int i = 0; i<n; i++){
            if (dist[i]==1e9){
                dist[i] = -1;
            }
        }
        return dist;

    }
};