#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0;
        int end = arr.size() - 1;        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int missingElements = arr[mid] - (mid + 1);
            if (missingElements >= k)
                end = mid - 1;
            else {
                start = mid + 1;   
            }
        }
        // int lower = arr[start-1] - (start); // how many missing numbers till lower limit
        // int upper = arr[start] - (start); // how many missing numbers till upper limit
        //kth positive integer that is missing, will lie between lower and upper
        //till arr[start-1] we have lower missing numbers
        //if we add (k-start-1) to  arr[start-1] then we get ans 
        //result is actually k - lower  + arr [start-1]
        //k - lower is the number of remaining missing numbers from lower onwards
        //so if we add (k-lower) to arr[start-1], then we can get to our result..
        return   k +  start;
    }
};  