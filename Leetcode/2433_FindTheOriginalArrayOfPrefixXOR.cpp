#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findArray(vector<int> &pref) {
    vector<int> res;
    res.push_back(pref[0]);
    for (int i = 1; i < pref.size(); i++) {
      res.push_back(pref[i - 1] ^ pref[i]);
    }
    return res;
  }
};
