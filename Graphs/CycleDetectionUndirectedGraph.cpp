#include <bits/stdc++.h>
using namespace std;
//BFS
class SolutionBFS {
  public:

    bool bfs(vector<int>* adj, int node, vector<int> &vis){
        queue<pair<int,int>>q;
        q.push({node,-1});
        vis[node] = 1;
        while(!q.empty()){
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto neighbour: adj[curr]){
                if (!vis[neighbour]){
                    q.push({neighbour,curr});
                    vis[neighbour] = 1;
                } else {
                    if (parent!=neighbour) return true;
                }
            }
        }
        return false;

    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V+1);
        for (int i = 0; i < V; ++i)
        {
            if (!vis[i]){
                if (bfs(adj,i, vis)) return true;
            }
        }
        return false;
    }
};

//DFS
class Solution {
  public:

    bool dfs(vector<int>* adj, int node, int parent, vector<int> &vis){
        vis[node] = 1;
        for(auto neighbour: adj[node]){
            if (!vis[neighbour]){
                if ( dfs(adj,neighbour,node,vis)) return true;
            } else {
                if (parent!=neighbour) return true;
            }
        }
        return false;
    }


    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V+1);
        for (int i = 0; i < V; ++i)
        {
            if(!vis[i]){
                if (dfs(adj,i,-1,vis)) return true;
            }
        }
        return false;
    }
};
