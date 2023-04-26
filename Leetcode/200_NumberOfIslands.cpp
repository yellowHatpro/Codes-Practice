#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> dx {0,-1,0,1};
	vector<int> dy {1,0,-1,0};
	void bfs(int m, int n, vector<vector<char>>&grid, vector<vector<int>>& vis, int row, int col){
		queue<pair<int,int>> q;
		q.push({row,col});
		vis[row][col]=1;
		while(!q.empty()){
			auto [x,y] = q.front();
			q.pop();
			for (int i = 0; i <4; ++i) {
				int r = x + dx[i];
				int c = y + dy[i];
				if (r>=0 && c>=0 && r<m && c<n && !vis[r][c] && grid[r][c]=='1'){
					q.push({r,c});
					vis[r][c] = 1;
				}
			}
		}
	}

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (!vis[i][j] && grid[i][j]=='1') {
        			ans++;
        			bfs(m, n, grid, vis, i, j);
        		}
        	}
        }
        return ans;
    }
};