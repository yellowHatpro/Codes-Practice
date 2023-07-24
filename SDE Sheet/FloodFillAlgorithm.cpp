#include <bits/stdc++.h>
using namespace std;

vector<int> dx{0,1,0,-1};
vector<int> dy{1,0,-1,0};

vector<vector<int>> bfs(int n, int m, vector<vector<int>>&vis, vector<vector<int>>&img, int x,int y, int newColor){
  queue<pair<int,int>> q;
  int color = img[x][y];
  q.push({x,y});
  vis[x][y]=1;
  vector<vector<int>> res(img.begin(),img.end());
  res[x][y] = newColor;
  while (!q.empty()) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++){
      int r = row+dx[i];
      int c = col+dy[i];
      if (r>=0 && c>=0 && r<n && c<m && !vis[r][c] && res[r][c]==color){
        res[r][c] = newColor;
        q.push({r,c});
        vis[r][c] = 1;
      }
    }
  }
  return res;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor){
  int n = image.size();
  int m = image[0].size();
  vector<vector<int>>vis(n,vector<int>(m,0));
  return bfs(n,m,vis,image,x,y,newColor);
}
