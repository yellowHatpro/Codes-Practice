#include <bits/stdc++.h> 
using namespace std;

//store color 0 or 1 in vis vector
bool bfs(vector<int>& vis, vector<vector<int>>& adj){
	queue<int> q;
	q.push(0);
	vis[0] = 0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for (auto neighbour: adj[node]){
			if (vis[neighbour]==-1){
				vis[neighbour] =  !vis[node];
				q.push(neighbour);
			} else if (vis[neighbour]==vis[node]){
				return false;
			}
		}
	}
	return true;
}


bool dfs(vector<int>& vis, vector<vector<int>> &adj, int node, int color){
	vis[node] = color;
	for(auto neighbour: adj[node]){
		if (vis[neighbour]==-1){
			if (!dfs(vis,adj,neighbour,!color)) return false;
		} else if (vis[neighbour] == color){
			return false;
		}
	}
	return true;
}

bool isBipartite(vector<vector<int>>& graph, int vertices, int edges)
{
	vector<vector<int>> adj(vertices+1);
	for (int i = 0; i < edges; ++i)
	{
		adj[graph[i][0]].push_back(graph[i][1]);
		adj[graph[i][1]].push_back(graph[i][0]);
	}
	vector<int> vis(vertices,-1);
	return dfs(vis,adj,0,0);
	//return bfs(vis,adj);
}