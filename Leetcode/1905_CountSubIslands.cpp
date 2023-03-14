#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	bool bfs(int i, int j, int n, int m, vector<vector<int>>& grid2, vector<vector<int>>& grid1, vector<vector<int>>& vis ){
		queue<pair<int,int>> q;
		q.push({i,j});
		vis[i][j] = 1;
        bool ans = true;
		vector<int> dx{0,-1,0,1};
		vector<int> dy{1,0,-1,0};
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
            if (grid1[x][y]==0){
                ans = false;
            }
			for (int i = 0; i < 4; ++i)
			{
				int r = x + dx[i];
				int c = y + dy[i];
				if (r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid2[r][c]==1){
					q.push({r,c});
					vis[r][c] = 1;
				}
			}
		}
		return ans;
	}

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < m; ++j)
        	{
        		if (grid2[i][j]==1 && !vis[i][j]  && bfs(i,j,n,m,grid2,grid1, vis)){
        			cnt++;
        		}
        	}
        }
        return cnt;
    }
};