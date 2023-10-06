#include <bits/stdc++.h>
using namespace std;

// Longest Consecutive Subsequence

int main() {
  int n;
  cin >> n;
  vector<int> input(n);
  for (int i = 0; i < n; i++) {
    cin >> input[i];
  }
  unordered_set<int> s(input.begin(), input.end());
  int largestLength = 0;
  for (auto itr : input) {
    if (s.find(itr - 1) == s.end()) {
      int curr = itr;
      int ans = 0;
      while (s.find(curr) != s.end()) {
        ans++;
        curr++;
      }
      largestLength = max(largestLength, ans);
    }
  }
  cout << largestLength << endl;
  return 0;
}
