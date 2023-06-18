#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod = 1e9+7;
    vector<int> dx{0,1,0,-1};
    vector<int> dy{1,0,-1,0};
    int dfs(int x, int y, vector<vector<int>>&grid,vector<vector<int>> &dp){
        if (dp[x][y]!=-1) return dp[x][y];
        int ans = 1;
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[x][y]<grid[nx][ny]){
                ans  = (ans%mod + dfs(nx,ny,grid,dp)%mod)%mod;
            }   
        }
        return dp[x][y] = ans%mod;
    }

    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        long long count = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                count = (count%mod + dfs(i,j,grid,dp)%mod)%mod;
            }
        }
        return (int)count%mod;
    }
};
