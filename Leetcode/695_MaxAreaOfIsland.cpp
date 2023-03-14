#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	int bfs(int rw, int cl, vector<vector<int>>& vis, int n, int m, vector<vector<int>>& grid ){
		int ans = 0;
		queue<pair<int,int>> q;
		q.push({rw,cl});
		vis[rw][cl]=1;
		while(!q.empty()){
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			ans++;
			for (int i = -1; i <=1; ++i)
			{
				int nrow = r+i;
				int ncol = c;
				while(nrow>=0 && nrow<=n-1 && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
					vis[nrow][ncol] = 1;
					q.push({nrow,ncol});
				}
			}
			for (int i = -1; i <=1; ++i){
				int nrow = r;
				int ncol = c+i;
				while(nrow>=0 && nrow<=n-1 && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
					vis[nrow][ncol] = 1;
					q.push({nrow,ncol});
				}
			}
		}
		return ans;
	}

    int maxAreaOfIsland(vector<vector<int>>& grid) {
    	int n = grid.size();
    	int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < m; ++j)
        	{
        		if (vis[i][j]==0 && grid[i][j]!=0) ans = max(ans,bfs(i,j,vis,n,m, grid));
        	}
        }
        return ans;
    }
};