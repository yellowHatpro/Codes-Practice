#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    bool isColorable(int col, vector<vector<int>>& adj, vector<int>& colors, int node){
      for(auto neighbour: adj[node]){
        if (colors[neighbour]==col) return false; 
    }
    return true;
  }

    bool f(vector<vector<int>>&adj, int m, int n, vector<int> &colors, int node){
      if (node==n) return true;
      for(int col=1; col<=m; col++){
        if (isColorable(col, adj, colors, node)){
          colors[node] = col;
          if (f(adj,m,n,colors,node+1)) return true;
          else colors[node] = 0;
      }
    }
    return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
      vector<vector<int>> adj(n);
      vector<int> colors(n);
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          if (graph[i][j]){
           adj[i].push_back(j);
           adj[j].push_back(i);
        }
      }
    }
    return f(adj,m,n,colors,0);
  }
};
