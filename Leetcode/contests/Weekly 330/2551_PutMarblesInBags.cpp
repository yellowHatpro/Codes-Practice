#include <bits/stdc++.h>
using namespace std;
//Upsolved
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k==weights.size() || k==1){
            return 0;
        }
        int n = weights.size();
        vector<int> v;
        for (int i = 0; i < n-1; ++i)
        {
            v.push_back(weights[i]+weights[i+1]);
        }
        sort(v.begin(), v.end());


    }
};