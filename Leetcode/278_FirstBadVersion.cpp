// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 0;
        int hi = n;
        int prev=0;
        while (lo<=hi){
            int mid = hi - (hi-lo)/2 ;
            if (isBadVersion(mid))
            {
                prev = mid;
                hi= mid -1;
            }
            else{
                lo = mid+1;
            }
        }
        return prev;
    }
};