#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	//Topological Sort using DFS
	bool dfs(vector<int>&vis, vector<int>&pathVis, int node, vector<vector<int>> &adj, vector<int>&ans){
		vis[node] = 1;
		pathVis[node] = 1;
		for(auto neighbour: adj[node]){
			if (!vis[neighbour]){
				if (!dfs(vis,pathVis,neighbour,adj,ans)) return false;
			} else if (pathVis[neighbour]) return false;
		}
		ans.push_back(node);
		pathVis[node] = 0;
		return true;
	}

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses);
        vector<int> pathVis(numCourses);
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        for (auto itr: prerequisites)
        {
        	adj[itr[1]].push_back(itr[0]);
        }
        for (int i = 0; i < numCourses; ++i)
        {
        	if (!vis[i]) 
        		if (!dfs(vis,pathVis,i,adj,ans)) return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};