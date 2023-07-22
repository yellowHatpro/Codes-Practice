#include <bits/stdc++.h>
using namespace std;
//return 1 if == m 
//return 0 if < m 
//return 2 if > m
double mult(double mid, int n, int m){
    long long ans = 1;
    for(int i = 1; i <=n; i++){
      ans*=mid;
      if (ans>m) return 2;
    }
    if (ans == m) return 1;
    return 0;
  }

int NthRoot(int n, int m) {
  double l = 1;
  double r = m;
  while(l<=r){
    int mid = (r+l)/2;
    if (mult(mid,n,m)==1) return mid;
    else if (mult(mid,n,m)==0) l = mid+1;
    else r = mid-1;
  }
  return -1;
}
