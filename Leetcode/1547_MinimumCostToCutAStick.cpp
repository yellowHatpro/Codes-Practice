#include <climits>
#include <functional>
using namespace std;

class Solution {
public:
  int minCost(int n, vector<int> &cuts) {
    int m = cuts.size();
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    vector dp(m + 1, vector<int>(m + 1, -1));
    function<int(int, int)> f = [&](int i, int j) -> int {
      if (i > j)
        return 0;
      if (dp[i][j] != -1)
        return dp[i][j];
      int cost = 0;
      int mini = INT_MAX;
      for (int idx = i; idx <= j; idx++) {
        cost = cuts[j + 1] - cuts[i - 1] + f(i, idx - 1) + f(idx + 1, j);
        mini = min(mini, cost);
      }
      return dp[i][j] = mini;
    };
    return f(1, m);
  }
};
