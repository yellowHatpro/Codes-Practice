#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	map<int,bool> m;
	bool res = false;
	void dfs(int start, vector<vector<int>> &adj, vector<int> &vis){
		if (m[start]) res =  true;
		vis[start] = 1;
		bool res = false;
		for(auto node: adj[start]){
			if (!vis[node]) dfs(node,adj,vis);
		}
	}

    bool canReach(vector<int>& arr, int start) {
    	int n = arr.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i)
        {	
        	if (arr[i]==0){
        		m[i] = 1;
        	}
        	if (i-arr[i]>=0){
        		adj[i].push_back(i-arr[i]);
        	}
        	if (i+arr[i]<n){
        		adj[i].push_back(i+arr[i]);
        	}
        }
        vector<int> vis(n);
        dfs(start,adj,vis);
        return res;
    }
};