#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool subArrayExists(int arr[], int n) {
    int sum = 0;
    set<int> s = {0};
    for (int i = 0; i < n; ++i) {
      sum += arr[i];
      if (s.find(sum) != s.end()) {
        return true;
      } else {
        s.insert(sum);
      }
    }
    return false;
  }
};
