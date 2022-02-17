#include <bits/stdc++.h>
using namespace std;
int main(){
    return 0;
}
class Solution {
    public:
//Trick is to traverse from the end of the arrays.
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  int n1i = m-1;
  int n2i = n-1;
  int i = m+n-1;
  while(n1i>=0 && n2i>=0){
      if(nums1[n1i]>nums2[n2i]){
          nums1[i] = nums1[n1i];
          n1i--;
      }
      else{
          nums1[i] = nums2[n2i];
          n2i--;
      }
        i--;
  }
    while(n1i>=0){
        nums1[i] = nums1[n1i];
        n1i--;
        i--;
    }
    while(n2i>=0){
        nums1[i] = nums2[n2i];
        n2i--;
        i--;
    }
    }
};
