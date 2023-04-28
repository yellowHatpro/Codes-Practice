#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
	vector<int> parent, rank;
	int cnt;
public:
	UnionFind(int size){
		parent.resize(size);
		rank.resize(size);
		cnt = size;
		for (int i = 0; i<size;i++) parent[i] = i;
	}
	int find(int x){
		if (parent[x]!=x) parent[x] = find(parent[x]);
		return parent[x];
	}

	void unionSet (int x, int y){
		int xset = find(x), yset = find(y);
		if (rank[xset]<rank[yset]){
			parent[xset] = yset;
		} else if (rank[xset]>rank[yset]){
			parent[yset] = xset;
		} else {
			parent[yset] = xset;
			rank[xset]++;
		}
	}
}

class Solution {
public:

	bool isSimilar(string a, string b){
		int diff = 0;
		for (int i = 0; i < a.size(); i++){
			if (a[i]!=b[i]) diff++;
		}
		return diff == 0 || diff == 2;
	}

	void dfs(vector<vector<int>>& adj, vector<int>& vis, int node){
		vis[node] = 1;
		for (auto neighbour: adj[node]){
			if (!vis[neighbour]){
				dfs(adj,vis,neighbour);
			}
		}
	}

	void bfs(vector<vector<int>>& adj, vector<int>&vis, int node){
		queue<int> q;
		q.push(node);
		vis[node] = 1;
		while(!q.empty()){
			int root = q.front();
			q.pop();
			for (auto neighbour: adj[root]){
				if (!vis[neighbour]){
					q.push(neighbour);
					vis[neighbour] = 1;
				}
			}
		}
	}

	int bsf_dfs_method(vector<string>& strs){
		int cnt = 0;
        vector<vector<int>> adj(strs.size());
        vector<int> vis(strs.size());
        for (int i = 0; i < strs.size(); ++i)
        {
        	for (int j = i+1; j < strs.size(); ++j)
        	{
        		if (isSimilar(strs[i],strs[j])){
        			adj[i].push_back(j);
        			adj[j].push_back(i);
        		}
        	}
        }
        for (int i = 0; i < strs.size(); ++i)
        {
        	if (!vis[i]){
        		cnt++;
        		bfs(adj,vis,i);
        	}
        }
        return cnt;
	}

	int dsuMethod(vector<string>& strs){
		UnionFind dsu(strs.size());
		int cnt = strs.size();
		for (int i = 0; i < strs.size(); ++i)
		{
			for (int j = i+1; j < strs.size(); ++j)
			{
				if (isSimilar(strs[i],strs[j]) && dsu.find(i)!=dsu.find(j)){
					cnt--;
					dsu.unionSet(i,j);
				}
			}
		}
		return cnt;
	}

    int numSimilarGroups(vector<string>& strs) {
    	//return bsf_dfs_method(strs);
    	return dsuMethod(strs);
    }
};