#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> dx{-1,0,1,0};
	vector<int> dy{0,1,0,-1};

	void bfs(int m, int n, vector<vector<int>>& vis, vector<vector<int>>& v, int sr, int sc, int col){
		int scol = v[sr][sc];
		queue<pair<int,int>> q;
		q.push({sr,sc});
		v[sr][sc] = col;
		vis[sr][sc] = 1;
		while(!q.empty()){
			auto [x,y] = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int r = x + dx[i];
				int c = y + dy[i];
				if (r>=0 && c>=0 && r<m && c<n && !vis[r][c] && v[r][c]==scol){
					v[r][c] = col;
					q.push({r,c});
					vis[r][c] = 1;
				}
			}
		}
	}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    	int m = image.size();
    	int n = image[0].size();
        vector<vector<int>> vis(m+1,vector<int>(n+1,0));
        vector<vector<int>> v = image;
        bfs(m,n,vis,v,sr,sc,color);
        return v;
    }
};