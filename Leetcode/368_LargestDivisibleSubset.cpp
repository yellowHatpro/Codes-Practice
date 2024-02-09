#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> a(n, 1), prev(n, -1);
    int max_len = 0, max_index = -1;

    for (int i = 0; i < n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (nums[i] % nums[j] == 0 && a[j] + 1 > a[i]) {
          a[i] = a[j] + 1;
          prev[i] = j;
        }
      }
      if (a[i] > max_len) {
        max_len = a[i];
        max_index = i;
      }
    }
    vector<int> result;
    while (max_index != -1) {
      result.push_back(nums[max_index]);
      max_index = prev[max_index];
    }

    reverse(result.begin(), result.end());
    return result;
  }
};
