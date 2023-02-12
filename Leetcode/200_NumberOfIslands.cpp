#include <bits/stdc++.h>
using namespace std;
class Solution {
public:


	void bfs(vector<vector<char>>&grid, vector<vector<int>>& vis, int row, int col){
		int n = grid.size();
		int m = grid[0].size();
		vis[row][col]=1;
		queue<pair<int,int>> q;
		q.push({row,col});
		while(!q.empty()){
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			for (int i = -1; i <=1; ++i)
			{
				int nrow = r+i;
				int ncol = c;
				while(nrow>=0 && nrow<=n-1 && ncol>=0 && ncol<m &&!vis[nrow][ncol] && grid[nrow][ncol]=='1'){
					vis[nrow][ncol] = 1;
					q.push({nrow,ncol});
				}
			}
			for (int i = -1; i <=1; ++i){
				int nrow = r;
				int ncol = c+i;
				while(nrow>=0 && nrow<=n-1 && ncol>=0 && ncol<m &&!vis[nrow][ncol] && grid[nrow][ncol]=='1'){
					vis[nrow][ncol] = 1;
					q.push({nrow,ncol});
				}
			}
		}

		return;
	}

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
        	for (int j = 0; j < n; ++j)
        	{
        		if (!vis[i][j] && grid[i][j]=='1'){
        			ans++;
        			bfs(grid, vis, i, j);
        		}
        	}
        }
        
        return ans;
    }
};