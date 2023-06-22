#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

int f(int prev, int idx, vector<vector<int>> &dp, auto arr, int n){
  if (idx == n-1) return 0;
  if (dp[idx][prev+1]!=-1) return dp[idx][prev+1];
  int notTake = f(prev,idx+1,dp,arr,n);
  int take = 0;
  if (arr[prev]<arr[idx]){
    take = 1 + f(idx+1,idx,dp,arr,n);
  }
  return dp[idx][prev+1] = max(take,notTake);
}

int longestBitonicSequence(vector<int>& arr, int n) {
  vector dp1(n, vector(n+1, -1));
  vector dp2(n, vector(n+1, -1));
  vector arr_rev = arr;
  reverse(arr_rev.begin(), arr_rev.end());
  f(-1,0, dp1, arr, n);
  f(-1,0,dp2,arr_rev, n);
  int maxi = 0;
  for (int i = 0; i < n; i++) {
    maxi = max(maxi,dp1[i]+dp2[i]-1);
  }
  return maxi;
} 

