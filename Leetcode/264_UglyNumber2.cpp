#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long>s;
        s.insert(1);
        int j=0;
        for(auto i:s)
        {
            j++;
            if(j==n){
                return i;
            }
            s.insert(i*2);
            s.insert(i*3);
            s.insert(i*5);
        }
        return -1;
    }
};
