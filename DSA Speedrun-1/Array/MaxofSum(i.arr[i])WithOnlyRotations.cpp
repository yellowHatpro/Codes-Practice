//
// Created by ashu on 22-04-2022.
//

#include "bits/stdc++.h"
using namespace std;
class MaxofSumixarrWithOnlyRotations
{
public:
    static int maxSum(vector<int> v, int n){
        int v_sum = 0;  // sum of v[i]
        int currval = 0; // sum of i*v[i]

        for (int i = 0; i < n; ++i) {
            v_sum += v[i];
            currval += i*v[i];
        }

        int max_sum = currval;

        // Traverse through all rotations
        for (int i = 1; i < n; ++i) {
            currval += v_sum - n*v[n-i];
            max_sum = max(max_sum, currval);
        }
        return max_sum;
    }
};

int main(){
    vector<int> v = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = v.size();
    cout<<MaxofSumixarrWithOnlyRotations::maxSum(v,n);
    return 0;
}