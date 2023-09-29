#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findLongestConseqSubseq(int arr[], int N) {
    unordered_set<int> s;
    for (int i = 0; i < N; ++i) {
      s.insert(arr[i]);
    }
    int longestStreak = 0;
    for (int i = 0; i < N; i++) {
      int itr = arr[i];
      if (s.find(itr - 1) == s.end()) {
        int currNum = itr;
        int currSteak = 1;
        while (s.find(currNum + 1) != s.end()) {
          currNum++;
          currSteak++;
        }
        longestStreak = max(longestStreak, currSteak);
      }
    }
    return longestStreak;
  }
};
