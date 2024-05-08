#include <bits/stdc++.h>
#include <string>
using namespace std;
class Solution {
public:
  vector<string> findRelativeRanks(vector<int> &score) {
    vector<string> res(score.size());
    map<int, int, greater<int>> m;
    for (int i = 0; i < score.size(); i++) {
      m[score[i]] = i;
    }
    int i = 0;
    for (auto [f, s] : m) {
      if (i == 0) {
        res[s] = "Gold Medal";
      } else if (i == 1) {
        res[s] = "Silver Medal";
      } else if (i == 2) {
        res[s] = "Bronze Medal";
      } else {
        res[s] = to_string(i + 1);
      }
      i++;
    }
    return res;
  }
};
