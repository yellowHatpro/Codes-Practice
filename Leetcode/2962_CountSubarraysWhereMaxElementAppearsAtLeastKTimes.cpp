#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    int ele = *max_element(nums.begin(), nums.end());
    long long ans = 0, st = 0;
    for (int en = 0; en < nums.size(); en++) {
      if (nums[en] == ele) {
        k--;
      }
      while (!k) {
        if (nums[st] == ele) {
          k++;
        }
        st++;
      }
      ans += st;
    }
    return ans;
  }
};

class SolutionAttempt2 {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    long long ans = 0;
    int ele = *max_element(nums.begin(), nums.end());
    int cnt = 0;
    for (int r = 0, l = 0; r < nums.size(); r++) {
      cnt += (nums[r] == ele);
      while (cnt >= k) {
        cnt -= (nums[l] == ele);
        l++;
      }
      ans += l;
    }
    return ans;
  }
};
