#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
    	sort(time.begin(), time.end());
    	ll l = 1;
    	ll r = (long long)time[0]*totalTrips;
    	ll ans = 1e15;
    	while(l<=r){
    		ll res = 0;
    		ll k = 0;
    		ll timestamp = (l+r)/2;
    		while( k<time.size() && timestamp/time[k]>0){
    			res+=(timestamp/time[k++]);
    		}
    		if (res<totalTrips){
    			l = timestamp+1;
    		} else{
                ans = min(ans,timestamp);
    		    r = timestamp-1;
    		}
    	}
    	return ans;
    }
};