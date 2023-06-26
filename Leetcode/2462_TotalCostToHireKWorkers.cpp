#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
      priority_queue<int,vector<int>, greater<int>> pq1;
      priority_queue<int,vector<int>, greater<int>> pq2;
      long long ans = 0;
      for (int  i = 0; i < candidates; i++) {
        pq1.push(costs[i]);
      }
      for (int i = max((int)candidates,(int)costs.size()-candidates); i< costs.size() ; i++) {
        pq2.push(costs[i]);
      }
    int nextHead = candidates;
    int nextTail = costs.size() - 1 - candidates;
    while (k--) {
      if (pq2.empty()  || (!pq1.empty() && pq1.top()<=pq2.top())) {
        ans+=pq1.top();
        pq1.pop();
        if (nextHead <= nextTail) {
          pq1.push(costs[nextHead++]);
        }
      } else {
        ans+=pq2.top();
        pq2.pop();
        if (nextHead <= nextTail) {
          pq2.push(costs[nextTail--]);
        }
      }
    }
    return ans;
    }
};
