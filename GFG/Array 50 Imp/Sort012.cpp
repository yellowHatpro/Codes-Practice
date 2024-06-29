#include <bits/stdc++.h>
using namespace std;

void sort012(int a[], int n) {
  int low = 0;
  int mid = 0;
  int hi = n - 1;
  while (mid <= hi) {
    if (a[mid] == 0) {
      swap(a[low], a[mid]);
      low++;
      mid++;
    } else if (a[mid] == 1) {
      mid++;
    } else if (a[mid] == 2) {
      swap(a[mid], a[hi]);
      hi--;
    }
  }
}
