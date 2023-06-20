#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:

    vector<int> topoSort(vector<vector<int>>&adj, int V){
    	vector<int> topo;
    	vector<int> inDegree(V);
    	for (int i = 0; i < adj.size(); ++i)
    	{
    		for(auto itr: adj[i]){
    			inDegree[itr]++;
    		}
    	}
    	queue<int> q;
    	for (int i = 0; i < V; ++i)
    	{
    		if (inDegree[i]==0) q.push(i);
    	}
    	while(!q.empty()){
    		int node = q.front();
    		q.pop();
    		topo.push_back(node);
    		for(auto neighbour: adj[node]){
    			inDegree[neighbour]--;
    			if (inDegree[neighbour]==0) q.push(neighbour);
    		}
    	}
    	return topo;
    }

    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
        for (int i = 0; i < N-1; ++i)
        {
        	string s1 = dict[i];
        	string s2 = dict[i+1];
        	for (int j = 0; j < min(s1.size(),s2.size()); ++j)
        	{
        		if (s1[j]!=s2[j]){
        			adj[s1[j]-'a'].push_back(s2[j]-'a');
        			break;
        		}
        	}
        }
        vector<int> topo = topoSort(adj,K);
        string res = "";
        for(auto itr: topo){
        	res+=char(itr+'a');
        }
        return res;
    }
};