#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        return __builtin_popcount(a^b);
        
    }
};
