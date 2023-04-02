#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>a, pair<int,int>b){
		return ((a.first-a.second )>(b.first - b.second));
	}
	
class Solution {
public:

    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward2.size();
        int ans = 0;
        vector<pair<int,int>> v;
        for (int i = 0; i < n; ++i)
        {
        	v.push_back({reward1[i],reward2[i]});
        }
        sort(v.begin(), v.end(), comp);
        for (int i = 0; i < n; ++i)
        {
        	if (i<k) ans+=v[i].first;
        	else ans+=v[i].second;
        }
        return ans;
    }
};