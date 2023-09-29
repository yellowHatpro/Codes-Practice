#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int mini = prices[0];
    int profit = 0;
    for (int i = 0; i < prices.size(); ++i) {
      mini = min(prices[i], mini);
      profit = max(profit, prices[i] - mini);
    }
    return profit;
  }
};
