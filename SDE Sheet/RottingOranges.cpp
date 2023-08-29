#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	vector<int> dx{0,1,0,-1};
	vector<int> dy{1,0,-1,0};

	pair<int,int> bfs(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis, queue<pair<pair<int,int>,int>>&q){
		int cnt = 0;
    int days = 0;
		while(!q.empty()){
			int x = q.front().first.first;
			int y = q.front().first.second;
      int day = q.front().second;
      days = max(days,day);
			q.pop();
			for (int z = 0; z < 4; ++z)
			{
				int r = x + dx[z];
				int c = y + dy[z];
				if (r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[r][c]!=0 ){
					if (grid[r][c]==1) cnt++;
					vis[r][c] = 1;
					q.push({{r,c},day+1});
				}
			}
		}
		return {cnt,days};

	}

    int orangesRotting(vector<vector<int>>& grid) {
    	int n = grid.size();
    	int m = grid[0].size();
      int totalFresh = 0;
		  queue<pair<pair<int,int>,int>> q;
      vector<vector<int>>vis(n+1,vector<int>(m+1,0));
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j){
          if (grid[i][j]==1) totalFresh++;
          if (grid[i][j]==2) {
            q.push({{i,j},0});
            vis[i][j]=1;
            }
        	}
        }
      auto ans = bfs(n,m,grid,vis,q);
      return ans.first == totalFresh ? ans.second : -1;
    }
};
