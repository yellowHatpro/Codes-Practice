#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int n = matrix.size();
      int m = matrix[0].size();
      int lo = 0;
      int hi = n+m-1;
      while(lo<=hi){
        int mid = (lo+hi)/2;
        if (matrix[mid/n][mid%n] > target){
          hi = mid - 1;
      } else if (matrix[mid/n][mid%n] < target){
          lo= mid + 1;
      } else return true;
    }
    return false;
    }
};
