#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    	vector<int> res(2);
    	int n = mat.size();
    	int m = mat[0].size();    	
    	for (int i = 0; i < n; ++i)
    	{	
    		int cnt = 0;
    		for (int j = 0; j < m; ++j)
    		{
    			if (mat[i][j]==1) cnt++; 	
    		}
    		if (cnt>res[1]){
    			res[0] = i;
    			res[1] = cnt;
    		}
    	}
    	return res;
    }
};