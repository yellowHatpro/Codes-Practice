#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
    int n = arr.size();
    double l = 0;
    double r = 1.0;
    while (l < r) {
      double mid = (l + r) / 2;
      double maxFraction =
          0.0; // maximum Fraction to store max fraction encountered
      int totalSmaller = 0; // total smaller fractions to count number of
                            // fractions smaller than mid
      int iNum = 0;
      int iDen = 0;
      int j = 1;
      for (int i = 0; i < n - 1; i++) {
        while (j < n && arr[i] >= mid * arr[j]) {
          j++;
        }
        totalSmaller += (n - j);
        if (j == n)
          break;
        double fraction = static_cast<double>(arr[i]) / arr[j];
        if (fraction > maxFraction) {
          iNum = i;
          iDen = j;
          maxFraction = fraction;
        }
      }
      if (totalSmaller == k) {
        return {arr[iNum], arr[iDen]};
      } else if (totalSmaller > k) {
        r = mid;
      } else {
        l = mid;
      }
    }
    return {};
  }
};
