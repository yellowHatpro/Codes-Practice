#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	vector<int> dx{0,1,0,-1};
	vector<int> dy{1,0,-1,0};

	int bfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis){
		int cnt = 0;
		queue<pair<int,int>> q;
		q.push({i,j});
		vis[i][j] = 1;
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int z = 0; z < 4; ++z)
			{
				int r = x + dx[z];
				int c = y + dy[z];
				if (r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[r][c]!=0){
					if (grid[r][c]==1) cnt++;
					vis[r][c] = 1;
					q.push({r,c});
				}
			}
		}
		return cnt;

	}

    int orangesRotting(vector<vector<int>>& grid) {
    	int n = grid.size();
    	int m = grid[0].size();
      	int cnt = 0;
      	int ones = 0;

        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < m; ++j)
        	{	if (grid[i][j]==1 ) ones++;
        		if (!vis[i][j] && grid[i][j]!=0){
        			cnt += bfs(i,j,n,m,grid,vis);
        		}
        	}
        }
        return ones-cnt==0 ? ;
    }
};