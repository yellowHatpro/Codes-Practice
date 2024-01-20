#include <bits/stdc++.h>
using namespace std;

// The trick here is to find the smallest number on the left and on the right of
// arr[i], as arr[i] will be the smallest between this range, and is only
// relevant in this range. Thus it boils down to Next Smaller Element, and
// Previous Smaller Element.

class Solution {
public:
  int MOD = 1e9 + 7;
  int sumSubarrayMins(vector<int> &arr) {
    stack<int> s;
    vector<int> leftSmaller, rightSmallerStrict;
    int n = arr.size();
    // checking for left first
    for (int i = 0; i < n; i++) {
      while (!s.empty() and arr[i] <= arr[s.top()])
        s.pop();
      if (s.empty())
        leftSmaller.push_back(-1);
      else
        leftSmaller.push_back(s.top());
      s.push(i);
    }
    while (!s.empty())
      s.pop();
    // check for right
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() and arr[s.top()] > arr[i]) {
        s.pop();
      }
      if (s.empty())
        rightSmallerStrict.push_back(n);
      else
        rightSmallerStrict.push_back(s.top());
      s.push(i);
    }
    reverse(rightSmallerStrict.begin(), rightSmallerStrict.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      // here, we are finding the product of the count of subarrays where arr[i]
      // is minimum sum of {(no. of subarrays where arr[i] is minimum) * arr[i]}
      // is the answer
      ans += static_cast<long long>(i - leftSmaller[i]) *
             (rightSmallerStrict[i] - i) * arr[i] % MOD;
      ans %= MOD;
    }
    return ans;
  }
};
