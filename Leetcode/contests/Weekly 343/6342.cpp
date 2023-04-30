#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        vector<ll> sumrow, sumcol;
        map<int,pair<int,int>> mp;
        int n = mat.size(); //rowsize
        int m = mat[0].size(); //colsize
        for (int i = 0; i < n; ++i)
        {
        	ll sum = 0;
        	for (int j = 0; j < m; ++j)
        	{
        		sum+=mat[i][j];
        		mp[mat[i][j]] = {i,j};
        	}
        	sumrow.push_back(sum);
        }

        for (int i = 0; i < m; ++i)
        {
        	ll sum = 0;
        	for (int j = 0; j < n; ++j)
        	{
        		sum+=mat[j][i];
        	}
        	sumcol.push_back(sum);
        }
        for (int i = 0; i < arr.size(); ++i)
        {
        	auto& [x,y] = mp[arr[i]];
        	sumrow[x]-=arr[i];
        	sumcol[y]-=arr[i];
        	if (sumrow[x]==0||sumcol[y]==0){
        		return i;
        	}
        }
        return 0;
    }
};