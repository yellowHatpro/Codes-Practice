#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int getMinDiff(int arr[], int n, int k) {
    set<pair<int, int>> s;
    // increase all elements by k once
    for (int i = 0; i < n; i++) {
      s.insert({arr[i] + k, 1});
    }
    int ans = *max_element(arr, arr + n) - *min_element(arr, arr + n);
    while (true) {
      auto itr = --s.end();
      if (itr->second == 1 &&
          itr->first - 2 * k >=
              0) { // it means we can subtract k from the original element
        s.insert({itr->first - 2 * k, 0}); // itr->second 0 because we can only
                                           // increase decrease only once
        s.erase(itr);
        ans = min(ans, s.rbegin()->first - s.begin()->first);
      } else
        break;
    }
    return ans;
  }
};
