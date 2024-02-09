#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string frequencySort(string s) {
    map<char, int> mp;
    vector<pair<int, char>> v;
    string ans = "";
    for (auto ch : s) {
      mp[ch]++;
    }
    for (auto i : mp) {
      v.push_back({i.second, i.first});
    }

    sort(v.begin(), v.end(), greater<pair<int, char>>());

    for (auto i : v) {
      while (i.first--)
        ans += i.second;
    }
    return ans;
  }
};
