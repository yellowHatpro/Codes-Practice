#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool good(double hour, vector<int>&dist, int m){
        double time = 0.0;
        for (int i = 0 ; i < dist.size(); i++) {
            double t = (double) dist[i] / (double) m;
            // Round off to the next integer, if not the last ride.
            time += (i == dist.size() - 1 ? t : ceil(t));
        }
        return time<=hour;
  }

    int minSpeedOnTime(vector<int>& dist, double hour) {
      int ans = -1;
      int l = 1;
      int r = 1e7;
      while(l<=r){
        int m = (l+r)>>1;
        if (good(hour,dist,m)){
        ans = m;
        r = m-1;
      }
        else l = m+1;
    }
    return ans;
    }
};
