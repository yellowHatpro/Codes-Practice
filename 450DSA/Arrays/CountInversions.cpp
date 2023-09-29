#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long int merge(long long *arr, long long *temp, long long l,
                      long long mid, long long r) {
    long long i = l, j = mid, k = l;
    long long int inv_cnt = 0;
    while ((i <= mid - 1) && (j <= r)) {
      if (arr[i] <= arr[j]) {
        temp[k++] = arr[i++];
      } else {
        inv_cnt += (mid - i); // this very imp
        temp[k++] = arr[j++];
      }
    }
    while (i <= mid - 1) {
      temp[k++] = arr[i++];
    }
    while (j <= r) {
      temp[k++] = arr[j++];
    }
    for (long long x = l; x <= r; ++x) {
      arr[x] = temp[x];
    }
    return inv_cnt;
  }

  long long int mergeSort(long long *arr, long long *temp, long long l,
                          long long r) {
    if (r > l) {
      long long mid = (r + l) / 2;
      long long int inv_cnt = mergeSort(arr, temp, l, mid);
      inv_cnt += mergeSort(arr, temp, mid + 1, r);
      inv_cnt += merge(arr, temp, l, mid + 1, r);
      return inv_cnt;

    } else
      return 0;
  }

  long long int inversionCount(long long *arr, long long N) {
    long long temp[N];
    return mergeSort(arr, temp, 0, N - 1);
  }
};
