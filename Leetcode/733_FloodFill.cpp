#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int col = 0;
	void bfs(queue<pair<int,int>> &q, map<pair<int,int>,int> &vis, vector<vector<int>> &res, vector<vector<int>>&image, int color){
		while(!q.empty()){
			pair<int,int> rc = q.front();
			q.pop();
			int n = image.size();
			int m  = image[0].size();
			for (int i = -1; i <=1; ++i)
			{
				int nrow = rc.first +i;
				int ncol = rc.second;
				while(nrow>=0 && nrow<=n-1 && ncol>=0 && ncol<m &&vis[{nrow,ncol}]==0 && image[nrow][ncol]==col){
					vis[{nrow,ncol}] = 1;
					res[nrow][ncol] = color;
					q.push({nrow,ncol});
				}
			}

			for (int i = -1; i <=1; ++i)
			{
				int nrow = rc.first ;
				int ncol = rc.second+i;
				while(nrow>=0 && nrow<=n-1 && ncol>=0 && ncol<m &&vis[{nrow,ncol}]==0 && image[nrow][ncol]==col){
					vis[{nrow,ncol}] = 1;
					res[nrow][ncol] = color;
					q.push({nrow,ncol});
				}
			}

		}
	}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        map<pair<int,int>,int> vis;
        int n = image.size();
		int m  = image[0].size();
        q.push({sr,sc});
        vis[{sr,sc}] = 1;
        vector<vector<int>> res(image.begin(), image.end());
        res[sr][sc] = color;
        col = image[sr][sc];
        bfs(q,vis,res, image, color);
        return res;
    }
};