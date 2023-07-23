#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int findMedian(vector<vector<int>> &A);
};

int countSmallerThanMid(vector<int> &row, int mid){
    int l = 0;
    int r = row.size()-1;
    while(l<=r){
      int m = (l+r)>>1;
      if (row[m]<=mid) l=m+1;
      else r = m-1;
  }
  return l;
}

int Solution::findMedian(vector<vector<int> > &A) {
  int l = 1;
  int r = 1e9;
  int n = A.size();
  int m = A[0].size();
  while(l<=r){
    int mid=(l+r)>>1;
    int cnt = 0; //<=mid
    for(int i = 0; i<n; i++){
      cnt+=countSmallerThanMid(A[i],mid);
    }
    if (cnt<=(n*m/2)) l = mid+1;
    else r = mid-1;
  }
  return l;
}

