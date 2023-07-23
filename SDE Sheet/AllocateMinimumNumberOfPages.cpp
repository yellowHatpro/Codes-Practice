#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
   int books(vector<int>&A, int B);
};

bool isPossiblePartition(vector<int>& v,int b, int val){
    int totalStudents=1;
    int sum=0;
    for(int i = 0; i<v.size(); i++){
      if (v[i]>val) return false;
      if (sum + v[i]<=val){
        sum+=v[i];
    } else {
      totalStudents++;
      sum=v[i];
    }
  }
  return totalStudents<=b;
}

int Solution::books(vector<int> &A, int B) {
  if (A.size()<B) return -1;
  int l = *min_element(A.begin(),A.end());
  int r = accumulate(A.begin(),A.end(),0);
  int ans=-1;
  while(l<=r){
    int m = (l+r)/2;
    if (isPossiblePartition(A, B, m)){
      r = m-1;
      ans = m;
    } else l = m+1;
  }
  return ans;
}

