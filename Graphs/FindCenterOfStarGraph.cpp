#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
 	vector<int> adj[n+2];
 	for (auto edge : edges ){
 		adj[edge[0]].push_back(edge[1]);
 		adj[edge[1]].push_back(edge[0]);
 	}
 	int ans = 0;
	
	for(int i = 1;i<=n+1;i++){
        if (adj[i].size() > 1){
            return i;
         
        }
    }
	return ans;
    }
};