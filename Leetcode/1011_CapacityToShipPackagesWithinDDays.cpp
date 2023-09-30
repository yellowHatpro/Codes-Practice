#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isAns(int mid, vector<int> &weights, int days) {
    int n = 1;
    int sum = 0;
    for (auto itr : weights) {
      if (sum + itr > mid) {
        sum = 0;
        n++;
      }
      sum += itr;
    }
    if (n > days) {
      return false;
    } else {
      return true;
    }
  }

  int shipWithinDays(vector<int> &weights, int days) {
    // Binary Search on answer
    // Range is Largest Element .. Sum of weights
    int l = *max_element(weights.begin(), weights.end());
    int r = accumulate(weights.begin(), weights.end(), 0);
    int ans = 0;
    while (l < r) {
      int mid = (l + r) / 2;
      if (isAns(mid, weights, days)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};
