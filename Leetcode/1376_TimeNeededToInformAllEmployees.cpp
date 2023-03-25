#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	int dfs(int head, vector<vector<int>> &adj, vector<int> & informTime){
		int maxi = 0;
		for (auto node: adj[head]){
			maxi = max(maxi,dfs(node,adj,informTime));
		}
		return maxi + informTime[head];
	}

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i)
        {
        	if (manager[i]!=-1) {
        		adj[manager[i]].push_back(i);
        	}
        }
        return dfs(headID,adj,informTime);
    }
};