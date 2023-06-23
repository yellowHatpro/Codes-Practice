#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int mod = 100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        q.push({start,0});
        vector<int> dist(100000,1e9);
        dist[start] = 0;
        while (!q.empty()) {
          auto itr = q.front();
          q.pop();
          int node = itr.first;
          int cnt = itr.second;
          for (auto itr : arr) {
            int num = (node*itr)%mod; // num is similar to next node or the "neighbour"
            if (cnt+1<dist[num]){
            dist[num] = cnt+1;
            if (num == end) return cnt+1;
            q.push({num,cnt+1});
        }
          }
        }
    return -1;
    }
};
