#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        vector<int> dx{0,1,0,-1};
        vector<int> dy{1,0,-1,0};
        queue<pair<int,int>> q;
        for (int i = 0; i < n; ++i)
        {
        	if (board[i][0] == 'O') {
        		q.push({i,0});
        	}
        	if (board[i][m-1] == 'O') {
        		q.push({i,m-1});
        	}
        }
        for (int i =0; i<m; i++) {
        	if (board[0][i]=='O') {
        		q.push({0,i});
        	}
        	if (board[n-1][i]=='O') {
        		q.push({n-1,i});
        	}
        }
        while(!q.empty()){
        	auto [x,y] = q.front();
        	vis[x][y] = 1;
        	q.pop();
        	for (int i = 0; i<4; i++){
        		int r = x + dx[i];
        		int c = y + dy[i];
        		if (r>=0 && r<n && c>=0 && c<m && !vis[r][c] && board[r][c]=='O'){
        			q.push({r,c});
        		}
        	}
        }
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < m; ++j)
        	{
        		if (!vis[i][j] && board[i][j]=='O') board[i][j] = 'X';
        	}
        }
        return;
    }
};