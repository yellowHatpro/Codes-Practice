#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    map<int, int> m;
    int prefixSum = 0;
    int cnt = 0;
    m[0]++;
    for (auto itr : nums) {
      prefixSum += itr;
      if (m[prefixSum - k] != 0) {
        cnt += m[prefixSum - k];
      }
      m[prefixSum]++;
    }
    return cnt;
  }
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = 0;
    vector<int> summedRow(m);
    for (int i = 0; i < n; i++) {
      fill(summedRow.begin(), summedRow.end(), 0);
      for (int j = i; j < n; j++) {
        for (int k = 0; k < m; k++) {
          summedRow[k] += matrix[j][k];
        }
        ans += subarraySum(summedRow, target);
      }
    }
    return ans;
  }
};
