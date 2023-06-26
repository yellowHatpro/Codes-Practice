#include <bits/stdc++.h>
using namespace std;

//For Directed Graphs
//Works on negative edges as well
//For undirected graphs, convert them to directed graphs
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n+1,1e8);
      for (int i = 0; i < n-1; i++) {
      dist[i] = 0;
        for (auto itr : edges) {
          int u = itr[0];
          int v = itr[1];
          int wt = itr[2];
          if (dist[u]!=1e8 && dist[u]+wt<dist[v]){
            dist[v] = dist[u] + wt;
        }
        } 
      }
      for (auto itr: edges){
        int u = itr[0];
        int v = itr[1];
        int wt = itr[2];
        if (dist[u]!=1e8  &&  dist[u]+wt < dist[v]){
          return 1;
      }
    }
   return 0; 
	}
};
