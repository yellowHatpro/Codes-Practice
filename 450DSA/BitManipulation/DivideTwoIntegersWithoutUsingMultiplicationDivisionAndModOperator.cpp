#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
      long long sign = (dividend<0 ^ divisor < 0) ? -1 : 1;
      dividend = abs(dividend);
      divisor = abs(divisor);
      long long q = 0, temp = 0;
      for (int i = 32; i >= 0; i--) {
        if (temp+(divisor << i ) <= dividend){
          temp+= divisor << i;
          q |= 1ll << i;

        }
      }
      q*=sign;
      return q;
    }
}; 
