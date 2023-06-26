#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;
class Solution
{ 

  vector<int> parents, rank;

	public:

    void unionByRank(int u, int v){
      int uPu = findParent(u);
      int uPv = findParent(v);
      if (rank[uPu]< rank[uPv]){
        parents[uPu] = uPv;
      } else if (rank[uPv] < rank[uPu]){
        parents[uPv] = uPu;
      } else {
        parents[uPv] = uPu;
        rank[uPu]++;
      }
    }

    int findParent(int node){
      if (node== parents[node]) return node;
      return parents[node] = findParent(parents[node]);
    }

    int spanningTree(int V, vector<vector<int>> adj[])
    {
      parents.resize(V+1);
      rank.resize(V+1);
      for (int i = 0; i < V; i++) {
        parents[i] = i;
      }
      vector<pair<int,pair<int,int>>> edges;
      for (int node= 0; node < V; node++) {
        for (auto itr  : adj[node]) {
          int wt = itr[1];
          int u = node;
          int v = itr[0];
          edges.push_back({wt,{u,v}});
        }
      }
      sort(edges.begin(),edges.end());
      int mstWt = 0;
      for (auto itr : edges) {
        int wt = itr.first;
        int u = itr.second.first;
        int v = itr.second.second;
        if (findParent(u)!=findParent(v)){
          mstWt+=wt;  
          unionByRank(u,v);
        }
      }
      return mstWt;
    }
};
