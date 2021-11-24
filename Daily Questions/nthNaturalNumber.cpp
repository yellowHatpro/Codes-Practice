/*
Given a positive integer N. You have to find Nth natural number after removing all the numbers containing digit 9.

Approach: Convert the number into base 9 and return answer.
Goood Question.. :) Work on Base conversions.
*/

#include <bits/stdc++.h>
#define ll long long
//base conversion
class Solution{
	public:
    	long long findNth(long long N)
    {
        //log n time
      ll ans = 0;
      ll i = 1;
      int rem = 0;
      while(N>0){
          rem = N%9;
          N/=9;
          ans=(rem*i)+ans;
          i*=10;
      }
        return ans;
        }
};
