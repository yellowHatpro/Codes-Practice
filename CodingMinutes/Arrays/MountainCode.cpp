#include <bits/stdc++.h>
using namespace std;

// Identify the peaks
// Then calculate the backward part of the peak, then move forward until you
// reach a valley, then repeat the process

// TC = O(n)
// SC = O(1)

class Solution {
public:
  int longestMountain(vector<int> &a) {
    int n = a.size();
    int longest = 0;
    for (int i = 1; i <= n - 2;) {
      // check a[i] is peak or not
      if (a[i] > a[i - 1] and a[i] > a[i + 1]) {
        int cnt = 1; // we included the peak
        int j = i;
        // count backward
        while (j >= 1 && a[j] > a[j - 1]) {
          j--;
          cnt++;
        }
        // count forward
        while (i <= n - 2 && a[i] > a[i + 1]) {
          i++;
          cnt++;
        }
        longest = max(longest, cnt);
      } else {
        i++;
      }
    }
    return longest;
  }
};
