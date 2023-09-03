#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    bool isSymmetric(int num) {
      int number = num;
      int cnt = 0;
      while(num>0){
      num/=10;
      cnt++;
    }
    int l = 0;
    int r = 0;
    if (cnt%2==0){
      int i = 0;
      while(i<cnt/2){
        l+=number%10;
        number/=10;
        i++;
      }
      while(i<cnt){
        r+=number%10;
        number/=10;
        i++;
      }
      return l==r;
    } else return false;
  }
      

    int countSymmetricIntegers(int low, int high) {
      int cnt = 0;
      for(int i = low; i <= high; i++){
        cnt+=isSymmetric(i);
      }
      return cnt;
    }
};
