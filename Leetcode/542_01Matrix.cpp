#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<int> dx{0,-1,0,1};
    vector<int> dy{1,0,-1,0};

    void dfs(pair<int,int> p, vector<vector<int>>& vis, vector<vector<int>>& grid, queue<pair<pair<int,int>,int>> &q, int n ){
        for(int i = 0; i<4;i++){
            int r = p.first + dx[i];
            int c = p.second + dy[i];
            if (r>=0 && r<n && c>=0 && c<n && !vis[r][c] && grid[r][c]==1){
                dfs({r,c}, vis, grid, q, n);
                vis[r][c]= 1;
                q.push({{r,c},0});
            }
        }
    }

    int bfs(vector<vector<int>> &grid, vector<vector<int>>& vis, int n ){
        queue<pair<pair<int,int>,int>> q;
        bool found = false;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j]==1){
                    found=true;
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                    dfs({i,j},vis,grid,q, n);
                    break;
                }
            }
            if (found) break;
        }

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int r = x + dx[i];
                int c = y + dy[i];
                if (r>=0 && r<n && c>=0 && c<n && !vis[r][c] && grid[r][c]==1){
                    return d;
                }
                if (r>=0 && r<n && c>=0 && c<n && !vis[r][c] && grid[r][c]==0){
                    q.push({{r,c},d+1});
                    vis[r][c] = 1;
                }
            }
        }
        return 0;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n+1, vector<int>(n+1,0));
        return bfs(grid,vis,n);
    }
};