#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0)) ;
        vector<vector<int>> dis(n,vector<int>(m,0));
       	queue<pair<pair<int,int>,int>> q;
       	for (int i = 0; i < n; ++i)
       	{
       		for (int j = 0; j < m; ++j)
       		{
       			if (mat[i][j]==0){
       				q.push({{i,j},0});
       				vis[i][j] = 1;
       			}
       		}
       	}
       	int delrow[] = {-1,0,+1,0};
       	int delcol[] = {0,1,0,-1}; 
       	while(!q.empty()){
       		int row = q.front().first.first;
       		int col = q.front().first.second;
       		int dist = q.front().second;
       		q.pop();
       		dis[row][col] = dist;
       		for (int i = 0; i < 4; ++i)
       		{
       			int newcol = col + delcol[i];
       			int newrow = row + delrow[i];
       			if (newrow>=0 && newrow<n && newcol>=0 && newcol <m && vis[newrow][newcol]==0){
       				vis[newrow][newcol] = 1;
       				q.push({{newrow,newcol},dist+1});
       			}
       		}

       	}
       	return dis;
    }
};