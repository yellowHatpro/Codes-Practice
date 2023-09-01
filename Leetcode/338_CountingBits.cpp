#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> countBits(int n) {
      if (n==0) return {0};
      vector<int> dp(n+1,0);
      dp[1] = 1;
      long long int pow2 = 2;
      int i = 2;
      while(i <= n){
        dp[i] = 1 + dp[i%pow2];
        if (i == pow2+pow2){
          pow2+=pow2;
        }
        i++;
      }
      return dp;
    }
};
