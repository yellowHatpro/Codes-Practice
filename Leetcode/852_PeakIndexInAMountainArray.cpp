#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      int l = 0;
      int r = arr.size()-1;
      while(l<=r){
        int m = (l+r)>>1;
        if (arr[m]<arr[m+1]){
          l = m+1;
        }
        else r = m-1;
    }
    return l;
  }
};
