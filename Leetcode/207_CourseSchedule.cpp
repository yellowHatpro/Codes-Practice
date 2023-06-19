#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	bool dfs(vector<int>& vis, vector<int>& pathVis, vector<vector<int>>&adj, int node){
		pathVis[node] = 1;
		vis[node] = 1;
		for(auto neighbour: adj[node]){
			if (!vis[neighbour]){
				if (!dfs(vis,pathVis,adj,neighbour)) return false;
			} else {
				if (pathVis[neighbour]) return false;
			}
		}
		pathVis[node] = 0; //this imp step
		return true;
	}

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses+1);
        vector<int> pathVis(numCourses+1);
        vector<vector<int>> adj(numCourses+1);
        for (int i = 0; i < prerequisites.size(); ++i)
        {
        	adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i < numCourses; ++i)
        {	
        	if (!vis[i]){
        		if (!dfs(vis,pathVis,adj,i)) return false;
        	} 
        }
        return true;
    }
};