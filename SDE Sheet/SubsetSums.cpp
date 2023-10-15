#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void f(vector<int> &arr, int n, int i, int sum, vector<int> &subsetSum) {
    if (i == n) {
      subsetSum.push_back(sum);
      return;
    }
    f(arr, n, i + 1, sum + arr[i], subsetSum);
    f(arr, n, i + 1, sum, subsetSum);
  }

  vector<int> subsetSums(vector<int> arr, int N) {
    vector<int> subsetSum;
    f(arr, N, 0, 0, subsetSum);
    sort(subsetSum.begin(), subsetSum.end());
    return subsetSum;
  }
};
