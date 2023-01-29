#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:


ll modpow(ll base, ll exp, ll modulus) {
  base %= modulus;
  ll result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

	ll power(ll x, unsigned ll y)
{
    
      ll temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;;
}
 
    int monkeyMove(int n) {
    	ll MOD = 1000000007;
        ll powe = (ll)modpow(2,n, MOD);
        ll kek = 2;
    	ll ans = (powe%MOD - kek%MOD)%MOD;
    	return ans;
    }
};