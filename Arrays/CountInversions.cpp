// GFG
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long int merge(long long *arr, long long *temp, int l, int mid, int r) {
    long long int invCount = 0;
    int i = l;
    int j = mid;
    int k = l;
    while ((i <= mid - 1) and (j <= r)) {
      if (arr[i] <= arr[j]) {
        temp[k++] = arr[i++];
      } else {
        temp[k++] = arr[j++];
        invCount += (mid - i);
      }
    }
    while (i < mid) {
      temp[k++] = arr[i++];
    }
    while (j <= r) {
      temp[k++] = arr[j++];
    }
    for (i = l; i <= r; i++) {
      arr[i] = temp[i];
    }
    return invCount;
  }

  long long int mergeSort(long long *arr, long long *temp, int l, int r) {
    int mid = 0;
    long long int invCount = 0;
    if (l < r) {
      mid = (l + r) / 2;
      invCount += mergeSort(arr, temp, l, mid);
      invCount += mergeSort(arr, temp, mid + 1, r);
      invCount += merge(arr, temp, l, mid + 1, r);
    }
    return invCount;
  }

  long long int inversionCount(long long arr[], long long n) {
    long long temp[n];
    long long int ans = mergeSort(arr, temp, 0, n - 1);
    return ans;
  }
};
