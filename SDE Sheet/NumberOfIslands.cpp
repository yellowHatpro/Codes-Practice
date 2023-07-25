#include <bits/stdc++.h>
using namespace std;


void bfs(int** arr, int n, int m, int i, int j, vector<vector<int>>&vis){
  queue<pair<int,int>> q;
  q.push({i,j});
  vis[i][j] = 1;
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(int g = -1; g<=1; g++){
      for(int h = -1; h <=1; h++){
        int r = x + g;
        int c = y + h;
        if (r>=0 && c>=0 && r<n && c<m && !vis[r][c] && arr[r][c]==1){
          q.push({r,c});
          vis[r][c] = 1;
        }
      }
    }
  }
}

int getTotalIslands(int** arr, int n, int m) {
  int ans = 0;
  vector<vector<int>> vis(n, vector<int>(m));
  for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if (!vis[i][j] && arr[i][j]==1){
          ans++;
          bfs(arr,n,m,i,j,vis);
      }
    }
  }
  return ans;
}

