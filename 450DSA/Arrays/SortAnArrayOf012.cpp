#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void sort012(int a[], int n) {
    int l = 0;
    int m = 0;
    int r = n - 1;
    while (m <= r) {
      if (a[m] == 0) {
        swap(a[m++], a[l++]);
      } else if (a[m] == 1) {
        m++;
      } else {
        swap(a[m], a[r--]);
      }
    }
  }
};
