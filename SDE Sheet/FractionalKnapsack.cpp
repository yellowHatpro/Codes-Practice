#include <bits/stdc++.h>
using namespace std;

struct Item {
  int value;
  int weight;
};

class Solution {
public:
  double fractionalKnapsack(int W, Item arr[], int n) {
    vector<pair<double, int>> vpw;
    double ans = 0;
    for (int i = 0; i < n; i++) {
      vpw.push_back({(double)arr[i].value / arr[i].weight, arr[i].weight});
    }
    sort(begin(vpw), end(vpw), greater<pair<double, int>>());
    for (auto itr : vpw) {
      if (W == 0) {
        return ans;
      }
      if (W - itr.second >= 0) {
        ans += (itr.first * itr.second);
        W -= itr.second;
      } else {
        ans += (itr.first * W);
        W = 0;
      }
    }
    return ans;
  }
};
