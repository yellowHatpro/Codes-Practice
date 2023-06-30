#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
      int lmask = y&(1<<(l-1));
      int ymask = 0;
      while(l<=r){
        ymask|=lmask;
        l++;
        lmask = y&(1<<(l-1));
    }
    return ymask|x;
  }
};

