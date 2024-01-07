#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    vector<vector<int>> dir = {{-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
    int i = c;
    int j = d;
    while (i <= 8 and j <= 8) {
      if (i == a and j == b) {
        break;
      }
      if (i == e and j == f) {
        return 1;
      } else {
        i++;
        j++;
      }
    }
    i = c;
    j = d;
    while (i >= 1 and j >= 1) {
      if (i == a and j == b)
        break;
      if (i == e and j == f) {
        return 1;
      } else {
        i--;
        j--;
      }
    }
    i = c;
    j = d;
    while (i <= 8 and j >= 1) {
      if (i == a and j == b)
        break;
      if (i == e and j == f) {
        return 1;
      } else {
        i++;
        j--;
      }
    }
    i = c;
    j = d;
    while (i >= 1 and j <= 8) {
      if (i == a and j == b)
        break;
      if (i == e and j == f) {
        return 1;
      } else {
        i--;
        j++;
      }
    }

    if (((a - e) == 0 or (f - b) == 0) and
        !(((a - c) == 0 and (c - e) == 0 and (abs(b - d) < abs(b - f) and abs(d-f) < abs(b-f))) or
          ((b - d) == 0 and (d - f) == 0 and (abs(a - c) < abs(a - e) and abs(c-e) < abs(a-e))))) {
      return 1;
    }
    return 2;
  }
};
