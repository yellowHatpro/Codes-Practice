#include <bits/stdc++.h>
#include <iterator>
using namespace std;

bool comp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
class SolutionGreedy {
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


class Solution {
public:
    
    int bs(vector<vector<int>>& intervals, int x, int l, int r){
      while(l<r){
		    int m = (l+r)/2;
		    if (intervals[m][0]>=x){
          r = m;
          }
		    else l = m+1;
      }
      return l;
  }

    int f(vector<int>& dp, vector<vector<int>>& intervals, int i){
      if (i==intervals.size()) return 0;
      if (dp[i]!=-1) return dp[i];
      int nextIndex = bs(intervals,intervals[i][1], i+1, intervals.size());
      int take = 1 + f(dp,intervals,nextIndex);
      int notTake = f(dp,intervals,i+1);
      return dp[i] =  max(take,notTake);
  }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());
      vector<int> dp(1e6,-1); 
      return intervals.size() -  f(dp,intervals,0);
    }
};

