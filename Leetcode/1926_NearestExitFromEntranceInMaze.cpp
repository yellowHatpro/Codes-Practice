#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> dx{1,0,-1,0};
	vector<int> dy{0,1,0,-1};

	int bfs(vector<int>& en, vector<vector<char>>& maze, int n, int m,vector<vector<int>>& vis){
		queue<pair<pair<int,int>, int>> q;
		q.push({{en[0], en[1]}, 1});
		vis[en[0]][en[1]] = 1;
		while(!q.empty()){
			int x = q.front().first.first;
			int y = q.front().first.second;
			int d = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int r = x + dx[i];
				int c = y + dy[i];

				if (r>=0 && r<n && c>=0 && c<m && !vis[r][c] && maze[r][c]=='.' &&( r!=en[0] || c!=en[1])){
					if(r==n-1||c==m-1 || r==0|| c==0) return d;
					q.push({{r,c},d+1});
					vis[r][c] = 1;
				}
			}
		}
		return -1;
	}

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    	int n = maze.size();
    	int m = maze[0].size();
        vector<vector<int>> vis(n+1,vector<int>(m+1,0));
        return bfs(entrance, maze, n,m , vis);
    }
};