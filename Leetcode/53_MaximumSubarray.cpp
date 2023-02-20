//There are 2 ways to solve this problem .
//1. Kadane's Algorithm
//2. Dynamic Programming


//1. Kadane's Algorithm - Maximum Subarray Problem
//Task -> Finding the largest sum of a contiguous subarray
/*
Pseudo Code :
Init:
    max_so_far = INT_MIN
    max_ending_here = 0
Loop for each element of the array
    a) max_ending_here = max_ending_here + arr[i]
    b) if(max_so_far < max_ending_here)
        max_so_far = max_ending_here
    c) if(max_ending_here < 0)
        max_ending_here = 0
return max_so_far
*/
#include <bits/stdc++.h>
using namespace std;
class SolutionKADANE {
public:
    int maxSubArray(vector<int>& arr) {
    int n = arr.size();
    int i = 0;
    int j = 0;
    int maxsum = INT_MIN;
    int currsum = 0;
    while(j<n){
        currsum+=arr[j++];
         maxsum = max(maxsum,currsum);
        if (currsum<=0){
            currsum=0;
            i=j;
        } 
    }
    return maxsum;
    }
};

//2. Dynamic Programming
class SolutionDP {
public:
    int maxSubArray(vector<int>& nums) {
        long long max_so_far = INT_MIN;
        long long max_ending_here = 0;
        for (auto itr = nums.begin(); itr !=nums.end(); itr++)
        {
         //include current element to prev subarr only when it can add to bigger number than itself. 
         if( *itr <= max_ending_here + *itr){
             max_ending_here += *itr;
         }  
         else{
             max_ending_here = *itr;
         }
         if (max_ending_here> max_so_far){
             max_so_far = max_ending_here;
         }
        
        }
         return max_so_far;
    }
};

class SolutionSlidingWindow{
public:
    int maxSubArray(vector<int>& arr){
        int n = arr.size();
        if (n==1) return arr[0];
        int l = 0;
        int ans = INT_MIN;
        int res =0;
        for (int r = 0; r<n;r++){
            res+=arr[r];
            while(res<arr[r] ){
                res-=arr[l];
                l++;
            }
            ans = max(res,ans);
        }
        return ans;
    }
};