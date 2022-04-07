#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
     int mySqrt(long long int x) {
        long long int lo=1;
        long long int hi = x;
         int ans = 0;
        while(lo<=hi){
        	long long int mid = lo + ((hi-lo)/2);
        	if (mid*mid==x)
        	{
        		return mid;
        	}
        	else if(mid*mid<=x){
        		ans = mid;
        		lo=mid+1;
        	}
        	else{
        		hi = mid-1;
        	}
        }
       return ans; 
    }
};