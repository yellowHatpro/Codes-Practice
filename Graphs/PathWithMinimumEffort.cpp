#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));  
        priority_queue<pair<int,pair<int,int>>, 
        vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        vector<int> dx{0,1,0,-1};
        vector<int> dy{1,0,-1,0};
        while (!pq.empty()) {
          auto it = pq.top();
          pq.pop();
          int diff = it.first;
          int x = it.second.first;
          int y = it.second.second;
          if (x==n-1 && y == m-1) return diff;
          for (int i = 0; i < 4; i++) {
            int r = x + dx[i];
            int c = y + dy[i];
            if (r>=0 && r<n && c>=0 && c<m){
              int newEff = max(abs(heights[x][y] - heights[r][c]),diff);
            if (newEff < dist[r][c]){
              dist[r][c] = newEff;
              pq.push({newEff,{r,c}});
          }
        }
          }
        }
    return 0;
    }
};
