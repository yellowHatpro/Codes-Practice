#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxOperations(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int cnt = 0;
    int i = 0;
    int j = nums.size() - 1;
    while (i < j) {
      if (nums[i] + nums[j] == k) {
        cnt++;
        i++;
        j--;
      } else if (nums[i] + nums[j] > k) {
        j--;
      } else
        i++;
    }
    return cnt;
  }
};
