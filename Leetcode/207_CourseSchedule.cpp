#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool  dfs(vector<vector<int>>& prerequisites, vector<vector<int>>& adj, vector<int>& vis, int i){
		if (vis[i]==1) return true;
			vis[i] = 1;
			for (auto j : adj[i]){
				if (vis[j]!=2){
					if (dfs(prerequisites, adj, vis, j)) return true;
				}
			}
			vis[i] = 2;
			return false;
	}

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    	int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < n; ++i)
        {
        	adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> vis(numCourses,0);
        for (int i = 0;i <numCourses;i++){
        	if (vis[i]==2) continue;
        	if (dfs(prerequisites, adj, vis, i)) return false	;
        }
        return true;
    }
};