#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    	int n = grid.size();
    	if (grid[0][0] || grid[n-1][n-1]) return -1;
        vector<vector<int>> retrace = grid;
        vector<pair<int,int>> dir{{1,1},{0,1},{1,0},{-1,1},{-1,-1},{-1,0},{1,-1},{0,-1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        retrace[0][0] = 1;
        while(!q.empty()){
        	int x = q.front().first;
        	int y = q.front().second;
        	if (x==n-1 && x==y) return retrace[x][y];
        	q.pop();
        	for(auto d: dir){
        		int r = x+ d.first;
        		int c = y+ d.second;
        		if (r>=0 && r<n && c>=0 && c<n  && retrace[r][c]==0){
        			retrace[r][c] = retrace[x][y] + 1;
        			q.push({r,c});
        		} 
        	}
        }
        return -1;
    }
};