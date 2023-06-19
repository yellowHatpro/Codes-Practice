#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int sum = 0;
        for (auto itr: gain){
            sum+=itr;
        	maxi = max(maxi,sum);
        }
        return maxi;
    }
};