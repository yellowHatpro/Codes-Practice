#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<pair<int,int>> pq;
        int n = reward2.size();
        map<int,int> m;
        int cnt1 = 0;
        int ans = 0;
        vector<pair<int,int>> v;
        for (int i = 0; i < n; ++i)
        {
        	if (reward1[i]>reward2[i]){
        		cnt1++;
        		v.push_back({reward1[i],reward2[i]});
        		m[reward1[i]]=i;
        	}
        	else {
        		pq.push({reward2[i],2});
        	}
        }
        
        for (int i = 0; i < n; ++i)
        {
        	pair<int,int> tp = pq.top();
        	pq.pop();
        	ans+=tp.first; 
        }
        return ans;
    }
};