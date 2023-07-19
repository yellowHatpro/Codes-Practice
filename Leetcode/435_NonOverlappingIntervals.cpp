#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), comp);
    int cnt = 0;
    int last = INT_MIN;
    for(int i = 0; i<intervals.size();i++){
      if (last>intervals[i][0]) cnt++;
      else {
        last = intervals[i][1];
      }
    }
    return cnt;
    }
};

