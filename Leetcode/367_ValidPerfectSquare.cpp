#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long lo = 0;
        long long hi = num;
        while(lo<=hi){
        	long long mid = hi-(hi-lo)/2;
        	if (mid*mid==num)
        	{
        		return true;
        	}
        	else if (mid*mid>num){
        		hi=mid-1;
        	}
        	else {
        		lo = mid+1;
        	}
        }
        return false;
    }
};