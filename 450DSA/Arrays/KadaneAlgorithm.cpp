#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
    	long long maxSum = arr[0];
    	long long maxSoFar = arr[0];
    	for (int i = 1; i < n; ++i)
    	{
    		maxSum = max((long long)arr[i], maxSum+(long long)arr[i]);
    		maxSoFar = max(maxSoFar, maxSum);
    	}
    	return maxSoFar ;
    }
};