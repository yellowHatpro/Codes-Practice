#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
      if (n==0) return 1;
      if (n==1.000) return x;
      double temp = myPow(x, n/2);
      if (n%2==0) return temp*temp;
      else return n<0 ? 1/x*temp*temp : temp*temp*x;
  }
};
