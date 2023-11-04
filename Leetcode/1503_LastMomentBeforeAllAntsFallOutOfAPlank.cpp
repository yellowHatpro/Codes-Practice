#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int getLastMoment(int n, vector<int> &left, vector<int> &right) {

    int l =
        (left.size() > 0) ? *max_element(left.begin(), left.end()) : INT_MIN;
    int r =
        (right.size() > 0) ? *min_element(right.begin(), right.end()) : INT_MAX;
    return max(n - r, l);
  }
};
