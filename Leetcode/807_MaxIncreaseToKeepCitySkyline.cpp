#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int sum=0;
        vector<int> vi;
        vector<int> vj;
        for (int i = 0; i < grid.size(); ++i)
        {	int maxi=0;
        	int maxj=0;
        	for (int j = 0; j < grid.size(); ++j)
        	{	
        		if (maxi<grid[i][j])
        		{
        			maxi=grid[i][j];
        		}
        		if (maxj<grid[j][i])
        		{
        			maxj=grid[j][i];
        		}
        	}
        	vi.push_back(maxi);
        	vj.push_back(maxj);
        }
      
        for (int i = 0; i < grid.size(); ++i)
        {
        	for (int j = 0; j < grid.size(); ++j)
        	{	int mn = min(vi[i],vj[j]);
        		if (grid[i][j]<mn)
        		{
        			sum+=(mn-grid[i][j]);
        		}
        	}
        }
        return sum;
    }
};