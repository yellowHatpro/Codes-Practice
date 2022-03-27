#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> numOne;
        map<int,int> m;
        	vector<int> res;
        for (int i = 0; i < mat.size(); ++i)
        {	int sum=0;
        	for (int j = 0; j < mat[i].size(); ++j)
        	{
        		if (mat[i][j]==1)
        		{
        			sum++;
        		}
        	}
        	m[i]=sum;
        }
        pair<int, int> p;
        for (int i = 0; i < m.size(); ++i)
        {	p.first = m[i];
        	p.second = i;
        	numOne.push_back(p);
        }
        sort(numOne.begin(), numOne.end());
 
        for (int i = 0; i < k; ++i)
        {
        	res.push_back(numOne[i].second);
        }
        return res;
    }
    
};