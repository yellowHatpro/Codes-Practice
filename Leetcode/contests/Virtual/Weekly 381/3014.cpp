#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumPushes(string word) {
    int ans = 0;
    int totalRounds = word.size() / 8;
    int incompleteRound = word.size() % 8;
    if (totalRounds == 0) {
      ans += incompleteRound;
    } else if (totalRounds == 1) {
      ans += 8 + (2 * incompleteRound);
    } else if (totalRounds == 2) {
      ans += 24 + (3 * incompleteRound);
    } else {
      ans += 48 + (4 * incompleteRound);
    }
    return ans;
  }
};
