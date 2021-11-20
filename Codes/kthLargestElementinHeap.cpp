#include <bits/stdc++.h>
using namespace std;
int kthLargest(int* arr, int n, int k) {
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    for(int j=0;j<k-1;j++){
        pq.pop();
    }
    return pq.top();
}