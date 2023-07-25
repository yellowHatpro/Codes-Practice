#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>&adj, int vertices, vector<int>&indegree){
  queue<int> q;
  for(int i = 1; i <= vertices; i++){
    if (indegree[i]==0) q.push(i);
  }
  int cnt = 0;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    cnt++;
    for(auto itr: adj[node]){
      indegree[itr]--;
      if (indegree[itr]==0) q.push(itr);
    }
  }
  return vertices!=cnt;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<vector<int>> adj(n+1);
  vector<int> indegree(n+1);
  for(auto itr: edges){
    adj[itr.first].push_back(itr.second);
    indegree[itr.second]++;
  }
  if (bfs(adj,n,indegree)) return 1;
  return 0;
}

