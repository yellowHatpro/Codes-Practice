#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	long long cnt = 1;
	void dfs(int node, vector<vector<int>>& adj, vector<int>&vis){
		vis[node] = 1;
		for (auto edge: adj[node]){
			if (!vis[edge]) {
				dfs(edge, adj,vis);
				cnt++;
				}
		}
	}

    long long countPairs(int n, vector<vector<int>>& edges) {
       	vector<vector<int>> adj(n);
       	vector<int> vis(n);
       	long long ans = 0;
       	for(auto edge: edges){
       		adj[edge[0]].push_back(edge[1]);
       		adj[edge[1]].push_back(edge[0]);
       	}
       	vector<long long> v;
       	for (int i = 0; i < n; ++i)
       	 {
       	 	if (!vis[i]){
       	 		dfs(i,adj,vis);
       	 		v.push_back(cnt);
       	 		cnt = 1;
       	 	}
       	 }
       	 vector<long long > v2 = v;
       	 for (int i = v2.size()-2; i>=0; i--){
       	 	v2[i] = v2[i] + v2[i+1];
       	 } 
       	 for (int i = 0; i < v.size()-1; ++i)
       	 {
       	 	ans+=v[i] * (v2[i] - v[i]);
       	 }
       	 return ans;
    }
};