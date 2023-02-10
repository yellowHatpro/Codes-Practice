#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	int distance(int i1, int j1, int i2, int j2){
		return( abs(i1-i2) + abs(j1-j2));
	}

    int maxDistance(vector<vector<int>>& grid) {
    	int ans = 0;
        int n = grid.size();
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < n; ++j)
        	{
        		for (int k = 0; k < n; ++k)
        		{
        				for (int l = 0; l < n; ++l)
        				{
        					if (i==k && j==l) continue;
        					if (grid[i][j]==1 && grid[k][l]==0){
        						ans = max(ans,distance(i,j,k,l));
        					}
        				}
        		}
        	}
        	return ans;
        }
    }
};