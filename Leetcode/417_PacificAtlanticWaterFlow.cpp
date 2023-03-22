#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    	int n = heights.size();
    	int m = heights[0].size();
    	vector<vector<int>> res;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i = 0; i<m;i++) q.push({0,i});
        for(int i = 1; i<n;i++) q.push({i,0});
        vector<int> dx{-1,0,1,0};
        vector<int> dy{0,1,0,-1};
        while(!q.empty()){
        	int x = q.front().first;
        	int y = q.front().second;
        	q.pop();
        	if (vis[x][y]) continue;
        	vis[x][y] = 1;
        	for(int i = 0; i<4;i++){
        		int r = x + dx[i];
        		int c = y + dy[i];
        		if (r>=0 && r<n && c>=0 && c<m && !vis[r][c] && heights[x][y]<=heights[r][c]){
        			q.push({r,c});
        		}
        	}
        }
        for (int i = m-1;i>=0;i--) q.push({n-1,i});
        for (int i = n-2;i>=0;i--) q.push({i,m-1});
        while(!q.empty()){
        	int x = q.front().first;
        	int y = q.front().second;
        	q.pop();
        	if (vis[x][y]==2) continue;
        	if (vis[x][y]==1) res.push_back({x,y});
        	vis[x][y] = 2;
        	for(int i = 0; i<4;i++){
        		int r = x + dx[i];
        		int c = y + dy[i];
        		if (r>=0 && r<n && c>=0 && c<m && vis[r][c]!=2 && heights[x][y]<=heights[r][c]){
        			q.push({r,c});
        		}
        	}
        }
        return res;
    }
};