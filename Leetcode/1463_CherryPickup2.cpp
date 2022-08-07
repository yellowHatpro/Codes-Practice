#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	int f(int r, int c, int i, int j1, int j2, vector<vector<int>> &grid,vector<vector<vector<int>>>&dp){
	int maxi = -1e8;
	if (j1<0 || j2<0 || j1>c||j2>c) return -1e8;
	if (i==r) {
		if(j1!=j2) return grid[i][j1]+grid[i][j2];	
		else return grid[i][j1];
	} 
	if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

	for(int itr = -1;itr<2;itr++){
		for(int jtr = -1;jtr<2;jtr++){
			int a = (j1!=j2) ? grid[i][j1] + grid[i][j2] + f(r,c,i+1,j1+itr,j2+jtr,grid,dp) : grid[i][j2] + f(r,c,i+1,j1+itr,j2+jtr,grid,dp);
			maxi = max(maxi,a);
		}
	}
	return dp[i][j1][j2] =  maxi;

}


    int cherryPickup(vector<vector<int>>& grid) {
    	int r = grid.size();
    	int c = grid[0].size();
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
	return f(r-1,c-1,0,0,c-1,grid,dp);
    }
};