#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; i++) {
          res[i].resize(i+1);
          res[i][0] = 1;
          res[i][i] = 1;
          for(int j = 1; j < i; j++){
            res[i][j] = res[i-1][j-1] + res[i-1][j];
      }
        }
    return res;
    }
};

//Calculating value of nCr
//Time : O(column) Space: O(1)
int nCr(int n, int r){
  long long res = 1;
  for(int i = 0; i < r; i++){
    res*=(n-i);
    res/=i+1;
  }
  return res;
}

int pascalTriangle(int row, int col){
  int element = nCr(row, col);
  return element;
}

