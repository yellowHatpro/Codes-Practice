//
// Created by ashu on 15-06-2022.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        long long ll = x;
        if (ll<0) {
            negative = true;
            ll*=-1;
        }
        string s = to_string(ll);
        std::reverse(s.begin(), s.end());
        if (stoll(s)>2147483647){
            return 0;
        }
        if (negative){
            return -1* stoi(s);
        }
        return stoi(s);
    }
};