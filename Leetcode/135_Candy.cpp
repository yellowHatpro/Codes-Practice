#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int candy(vector<int> &ratings) {
    if (ratings.size() == 1)
      return 1;
    long long res = 1, i = 1, n = ratings.size();
    long long currEle = 1;
    while (i < n) {
      // Going Down
      if (ratings[i] < ratings[i - 1]) {
        int cnt = 1;
        int localSum = 1;
        while (i < n && ratings[i] < ratings[i - 1]) {
          cnt++;
          localSum += cnt;
          i++;
        }
        if (currEle < cnt) {
          res = res + localSum - currEle;
          currEle = 1;
        } else {
          localSum -= cnt;
          res += localSum;
        }
        currEle = 1;
      }
      // Going Up
      else if (ratings[i] > ratings[i - 1]) {
        currEle = 1;
        while (i < n && ratings[i] > ratings[i - 1]) {
          currEle++;
          res += currEle;
          i++;
        }
      }
      // Same ratings
      else if (ratings[i] == ratings[i - 1]) {
        while (i < n && ratings[i] == ratings[i - 1]) {
          res++;
          i++;
        }
        currEle = 1;
      }
    }
    return res;
  }
};
