#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
    	int totalSum = 0;
    	for (auto itr: arr){
    		totalSum+=itr;
    		}
        int n = arr.size();
        if (n==1) return arr[0];
        int l = 0;
        int ans = INT_MAX;
        int res =0;
        for (int r = 0; r<n;r++){
            res+=arr[r];
            while(res>arr[r] ){
                res-=arr[l];
                l++;
            }
            ans = min(res,ans);
        }
        return ans;
    }
};