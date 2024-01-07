#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int areaOfMaxDiagonal(vector<vector<int>> &dimensions) {
    int maxi = 0;
    int maxindex = 0;
    for (int i = 0; i < dimensions.size(); i++) {
      int sq = dimensions[i][0] * dimensions[i][0] +
               dimensions[i][1] * dimensions[i][1];
      if (sq > maxi) {
        maxi = sq;
        maxindex = i;
      } else if (sq == maxi) {
        if (dimensions[i][0] * dimensions[i][1] >
            dimensions[maxindex][0] * dimensions[maxindex][1]) {
          maxi = sq;
          maxindex = i;
        }
      }
    }
    return dimensions[maxindex][0] * dimensions[maxindex][1];
  }
};
