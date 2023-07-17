#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n) {
      vector<pair<int,int>> v;
      for(int i=0; i<n; i++){
        v.push_back({end[i],start[i]});
      }
      sort(v.begin(), v.end());
      int cnt = 1;
      int endtime = v[0].first;
      for(int i = 1; i<n; i++){
        if (endtime<v[i].second){
          cnt++;
          endtime = v[i].first;
        }
      }
      return cnt;
    }
};

