#include <bits/stdc++.h>
#include <iterator>
using namespace std;
class Solution {
public:
  int minimumPushes(string word) {
    map<char, int> m;
    vector<int> freq;
    for (auto c : word) {
      m[c]++;
    }
    for (auto [f, s] : m) {
      freq.push_back(s);
    }
    sort(begin(freq), end(freq), greater<int>());
    int ans = 0, row = 1;
    for (int i = 0; i < freq.size(); i++) {
      if (i >= 8 and i % 8 == 0) {
        row++;
      }
      ans += row * (freq[i]);
    }
    return ans;
  }
};
