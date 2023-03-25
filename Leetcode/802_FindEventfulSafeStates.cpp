#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	bool dfs(int node, vector<vector<int>> &graph, vector<int>& vis){
		if (vis[node]>0) return vis[node]==2;
		vis[node] = 1;
		for (auto edge: graph[node]){
			if (vis[edge]==2) continue;
			if (!dfs(edge,graph,vis) || vis[edge]==1) return false;
		}
		vis[node] = 2;
		return true;
	}

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> v;
        vector<int> vis;
        for (int i = 0; i < n; ++i)
        {
        	if (dfs(i,graph,vis)){
        		v.push_back(i);
        	}
        }
        return v;
    }
};