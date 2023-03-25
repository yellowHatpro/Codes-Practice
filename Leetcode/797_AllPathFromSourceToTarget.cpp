#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	void dfs(int node, vector<vector<int>>& graph, vector<vector<int>> &res, vector<int> path){
		path.push_back(node);
		if (node == graph.size()-1){
				res.push_back(path);
			}
		for(auto edge: graph[node]){
			dfs(edge, graph,res, path);
		}
	}

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    	int n = graph.size();
        vector<vector<int>> res;
		vector<int> path;
        dfs(0,graph,res, path);
        return res;
    }
};