#include <bits/stdc++.h>
using namespace std;
//intuition: 
//1. find the just smaller 2's power : x
//2. count set bits from 1 till 2^x : there will be total x*(2^(x-1)) set bits 
//3. count from 2^x till n : extract the leftmost set bit from them ex:
//n = 10
//0:  0 0 0 0
//1:  0 0 0 1
//2:  0 0 1 0
//3:  0 0 1 1
//4:  0 1 0 0
//5:  0 1 0 1
//6:  0 1 1 0
//7:  0 1 1 1
//8:  1 0 0 0 extract 1 from left, it will become 0
//9:  1 0 0 1 extract 1 from left, it will become 0 0 1 (1)
//10: 1 0 1 0 extract 1 from left, it will become 0 1 0 (2)
//thus call the recursive function again on n - 2^x 
class Solution{
    public:
    int countSetBits(int n)
    {
        if (n<=0) return 0;
        int x = 0;
        while((1<<x)<=n){
        x++;
        }
      x--;
      int cnt = x*(1<<(x-1)) + n - (1<<x) + 1 + countSetBits(n-(1<<x));
      return cnt;
    }
};
