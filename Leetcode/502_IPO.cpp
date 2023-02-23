#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       vector<pair<int,int>> cp;
       int n = profits.size();
       for (int i = 0; i < n; ++i)
       {
       		cp.push_back({capital[i],profits[i]});
       }
       sort(cp.begin(), cp.end());
       int ptr = 0;
       int weight = w;
       priority_queue<int> q;
       for (int i = 0; i < k; ++i)
       {
       	while(ptr<n && cp[ptr].first<=weight){
       	
       		q.push(cp[ptr++].second);
       	}
       	if (q.empty()) break;
       	weight+=q.top();
       	q.pop();
       }
       return weight;
    }
};