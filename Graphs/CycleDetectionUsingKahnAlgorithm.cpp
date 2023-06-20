#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> inDegree(V);
        for (int i = 0; i < V; ++i)
        {
        	for(auto itr: adj[i]){
        		inDegree[itr]++;
        	}
        }
        int cnt = 0;
        queue<int> q;
        for (int i = 0; i < V; ++i)
        {
        	if (inDegree[i]==0){
        		q.push(i);
        	}
        }
        while(!q.empty()){
        	int node = q.front();
        	q.pop();
        	cnt++;
        	for(auto neighbour: adj[node]){
        		inDegree[neighbour]--;
        		if(inDegree[neighbour]==0) q.push(neighbour);
        	}
        }
        return cnt!=V;
    }
};