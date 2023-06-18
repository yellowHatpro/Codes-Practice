#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> dx{0,1,0,-1};
	vector<int> dy{1,0,-1,0};
	int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>> &dp){
		if (dp[x][y]!=-1) return dp[x][y];
		int ans = 1;
		int maxDFS = 0;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx>=0 && ny>=0 && nx<matrix.size() && ny<matrix[0].size() && matrix[nx][ny]>matrix[x][y]){
				maxDFS = max(maxDFS,dfs(nx,ny,matrix,dp));
			}
		}
		ans += maxDFS;
		return dp[x][y] = ans;
	}

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < m; ++j)
        	{
        		ans = max(ans,dfs(i,j,matrix,dp));
        	}
        }
        return ans;
    }
};