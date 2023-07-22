#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> dx{1,0,0,-1};
    vector<int> dy{0,-1,1,0};
  vector<char> dir{'D','L','R','U'};
    void f(vector<vector<int>>&m, int n, vector<vector<int>> &vis, vector<string>& res, int x, int y, string s){
      if (x==n-1 && y==n-1){
        res.push_back(s);
        return;
      }
      for(int i = 0; i < 4; i++){
        int row = x + dx[i];
        int col = y + dy[i];
        if (row<n && row>=0 && col<n && col>=0 && !vis[row][col] && m[row][col]){
          vis[x][y] = 1;
          f(m,n,vis,res,row,col,s+dir[i]);
          vis[x][y] = 0;
        }
      }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
      if (!m[0][0]) return {};
      vector<vector<int>> vis(n,vector<int>(n,0));
      vector<string> res;
      f(m,n,vis,res,0,0,"");
      return res;
  }
};
