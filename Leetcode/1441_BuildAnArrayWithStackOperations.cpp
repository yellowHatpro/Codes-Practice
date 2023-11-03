#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> buildArray(vector<int> &target, int n) {
    string push = "Push";
    string pop = "Pop";
    int idx = 0;
    vector<string> v;
    for (int i = 1; i <= target[target.size() - 1]; i++) {
      v.push_back(push);
      if (i != target[idx]) {
        v.push_back(pop);
      } else {
        idx++;
      }
    }
    return v;
  }
};
