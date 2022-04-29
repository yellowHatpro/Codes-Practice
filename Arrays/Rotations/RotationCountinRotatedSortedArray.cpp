//
// Created by ashu on 23-04-2022.
//

#include <bits/stdc++.h>
using namespace std;

/*
 * Consider an array arr of distinct numbers sorted in increasing order.
 * Given that this array has been rotated (clockwise) k number of times.
 * Given such an array,
 * find the value of k.
 */

int countRotationsLinear(vector<int> arr, int n){
    int min = arr[0];
    int min_index;
    for (int i = 0; i < n; ++i) {
        if (min>arr[i]){
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

// Using binary search

int countRotationsLog(vector<int> arr, int low, int high){
    if (low> high) return 0;// When array is not rotated

    if (high==low) return low;

    int mid = (low+high)/2;

    if (mid<high && arr[mid]>arr[mid+1]) return mid+1;

    if (mid>low && arr[mid]<arr[mid-1]) return mid;

    if (arr[high]>arr[mid]) return countRotationsLog(arr, low, mid-1);//If middle element is smaller than the right most element, then minimum element is in the left half

    return countRotationsLog(arr, mid+1, high);
}

int main  (){
    vector<int> arr = {15, 18, 2, 3, 6, 12};
    int n = arr.size();
    cout<<countRotationsLog(arr, 0, n-1)<<endl;
    return 0;
}