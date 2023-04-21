// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
    long long int l = 0;
    long long int r = (long long int)n+1;
    while(r>l+1){
        long long int m = r - (r-l)/2;
        if (isBadVersion(m)) r = m;
        else l = m;
    }
    return r;
    }
};