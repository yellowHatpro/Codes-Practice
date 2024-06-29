#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

class Solution {
public:
  int minDays(vector<int> &bloomDay, int m, int k) {
    // Days 1 -> Max(arr)
    // min = 1;
    // max = arr.max
    // (1 + x) <=2*maxItem
    int l = 1;
    int r = 2 * (*max_element(begin(bloomDay), end(bloomDay)));
    int ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      // Current day check if m bouquests can be made
      int cnt = 0;
      int windowSize = 0;
      for (int i = 0; i < bloomDay.size(); i++) {
        if (bloomDay[i] <= mid) {
          windowSize++;
        } else {
          windowSize = 0;
        }
        if (windowSize == k) {
          cnt++;
          windowSize = 0;
        }
      }
      if (cnt >= m) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  }
};
