#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
    	int n = graph.size();
		if (n==1) return 0;
        map<pair<int,int>,bool> vis;
        queue<pair<int,int>> q;
        for (int i = 0; i < n; ++i)
        {
        	q.push({i,1<<i});
        }
        int finalState = (1<<n) -1;
        int ans = 0;
        while(!q.empty()){
        	ans++;
        	int sz = q.size();
        	for (int i = 0; i < sz; ++i)
        	{
        		int node = q.front().first;
        		int currentBitState = q.front().second;
        		q.pop();
        		for ( auto neighbour: graph[node]){
        			int newBitState =(currentBitState | (1<<neighbour));
        			if (newBitState==finalState){
        				return ans;
        			}
        			if (!vis[{neighbour,newBitState}]){
        				vis[{neighbour,newBitState}] = true;
        				q.push({neighbour,newBitState});
        			}
        		}
        	}
        }
        return -1;
    }
};