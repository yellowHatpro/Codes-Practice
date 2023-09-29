#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> getMinMax(long long a[], int n) {
  long long min = a[0];
  long long max = a[0];
  for (int i = 0; i < n; ++i) {
    if (a[i] < min) {
      min = a[i];
    } else if (a[i] > max) {
      max = a[i];
    }
  }
  return {min, max};
}
