#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (numOnes>=k){
        	return k;
        }
        if (k<=(numOnes+ numZeros)){
        	return (numOnes);
        }
        else{
        	int n = k - numOnes;
        	return numOnes-n;
        }
    }
};