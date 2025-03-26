#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
  int minOperations(vector<vector<int>> &grid, int x) {
    vector<int> v;
    int res = 0;
    for (auto itr : grid) {
      for (auto c : itr) {
        v.push_back(c);
      }
    }
    // TIP: We could have used nth_element sort method here to just find median
    sort(v.begin(), v.end());
    int median = v[v.size() / 2];
    for (auto itr : v) {
      int jump = abs(median - itr);
      if (jump % x != 0)
        return -1;
      res += jump / x;
    }
    return res;
  }
};
