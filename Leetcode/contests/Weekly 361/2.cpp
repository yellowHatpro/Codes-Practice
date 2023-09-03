#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(string num) {
      num = '0' + num;
      int mini1 = INT_MAX;
      int mini2 = INT_MAX;
      int n = num.size();
      char r = 'F';
      int cnt = 0;
      for(int i = n-1; i>=0; i--){
        if (r=='F'){
          if (num[i]=='0'){
            r = num[i];
        } else cnt++;
        } else {
          if (num[i]=='5' || num[i]=='0'){
            mini1 = min(mini1, cnt);
            break;
        } else cnt++;
      }
      }
      cnt = 0;
      r='F';
      for(int i = n-1; i>=0; i--){
        if (r=='F'){
          if (num[i]=='5'){
            r = num[i];
        } else cnt++;
        } else {
          if (num[i]=='2' || num[i]=='7'){
            mini2 = min(mini2, cnt);
            break;
        } else cnt++;
       }
      }
      return min({mini1,mini2,n-1});
    }
};
