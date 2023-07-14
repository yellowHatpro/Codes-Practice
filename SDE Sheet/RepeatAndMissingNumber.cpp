#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;

class Solution{
  vector<int> repeatedNumberMath(const vector<int>&A);
  vector<int> repeatedNumber(const vector<int>&A);
};

vector<int> Solution::repeatedNumberMath(const vector<int> &A) {
  long long n = A.size();
  long long totalSum = 0;
  long long sqSum = 0;
  for (int i = 0; i < n; i++) {
    totalSum+=A[i];
    sqSum += (long long)((long long)A[i]*(long long)A[i]);
  }
  long long sn = (long long)(n*(n+1))/2;
  long long s2n = (long long)((long long)(n*(n+1))*(2*n+1))/6ll;
  long long a=totalSum-sn;
  long long b =sqSum-s2n;
  long long c = b/a;
  long long x = (a+c)/2;
  long long y = (c-a)/2;
  return {(int)x, (int)y};
}

vector<int> Solution::repeatedNumber(const vector<int> &A){
  int xr = 0;
  for(int i = 0; i < A.size(); i++){
    xr^=A[i];
    xr^=(i+1);
  }
  int rightMostSetBit = xr&-xr;
  int one = 0;
  int zero = 0;
  for(auto itr: A){
    if (itr&rightMostSetBit) one^=itr;
    else zero^=itr;
  }
  for(int i = 1; i <=A.size(); i++){
    if (i&rightMostSetBit) one^=i;
    else zero^=i;
  }
  int cnt = 0;
  for(auto itr: A){
    if (itr==one) cnt++;
  }
  if (cnt==2) return {one,zero};
  return {zero,one};
}

