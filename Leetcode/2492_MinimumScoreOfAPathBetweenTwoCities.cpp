#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	int bfs(vector<vector<pair<int,int>>> &adjList, vector<int>& vis){
		queue<int> q;
		int cnt = INT_MAX;
		q.push(1);
		vis[1]=1;
		while(!q.empty()){
			int ele = q.front();
			q.pop();
			for(auto node: adjList[ele]){
				cnt = min(node.second,cnt);
				if (!vis[node.first]){
					vis[node.first] = 1;
					q.push(node.first);
				}
			}
		}
		return cnt;
	}

    int minScore(int n, vector<vector<int>>& roads) {
    	vector<vector<pair<int,int>>> adjList(n+1);
    	for (auto road: roads)
    	{
    		adjList[road[0]].push_back({road[1], road[2]});
    		adjList[road[1]].push_back({road[0], road[2]});
    	}
    	vector<int> vis(n+1);
    	return bfs(adjList,vis);
    }
};