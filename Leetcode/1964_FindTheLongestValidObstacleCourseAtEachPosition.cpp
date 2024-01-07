#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles) {
    // This is a variation of Longest Increasing Subsequence, but here we will
    // check for Longest Non-decreasing subsequence. LIS and this problem can be
    // solved with a O(n2) solution, but, also with a O(nlogn) Binary+Greedy
    // solution.
    vector<int> lengthOfLISAtEachIndex(obstacles.size());
    vector<int> LIS;
    LIS.push_back(obstacles[0]);
    lengthOfLISAtEachIndex[0] = 1;
    for (int i = 1; i < obstacles.size(); ++i) {
      if (obstacles[i] >= LIS.back()) {
        LIS.push_back(obstacles[i]);
        lengthOfLISAtEachIndex[i] = LIS.size();
      } else {
        int idx =
            upper_bound(LIS.begin(), LIS.end(), obstacles[i]) - LIS.begin();
        LIS[idx] = obstacles[i];
        lengthOfLISAtEachIndex[i] = idx + 1;
      }
    }
    return lengthOfLISAtEachIndex;
  }
};
