#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int minimumCost(int n, int m, int x, vector<int> &p, vector<vector<int>> &A) {
    	vector<int> sortedsomething = p;
    	sort(sortedsomething.begin(), sortedsomething.end());
    	map<int, int> mp;
    	for (int i = 0; i < p.size(); ++i)
    	{
    		auto itr = find(p.begin(), p.end(), sortedsomething[i]);
    		sortedsomething[i] = -1;
    		mp[i] = itr - p.begin();
    	}
    	int ans = 0;
    	int courseSum = 0;
    	set<int> s;
    	for (int j = 0; j < m; ++j)
    	{	int cnt = 0;
    		for (auto i: mp){
    			if (cnt>=x) break;
    			s.insert(i.second);
    			cnt+=A[i.second][j];
    		}
    		if (cnt<x){
    			return -1;
    		}
    	}
    	for(auto itr: s){
    		ans+=p[itr];
    	}
    	return ans;
	}
};