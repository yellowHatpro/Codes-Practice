#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int> &barcodes) {
    map<int, int> m;
    for (auto itr : barcodes) {
      m[itr]++;
    }
    set<pair<int, int>, greater<pair<int, int>>> s;
    for (auto itr : m) {
      s.insert({itr.second, itr.first});
    }
    vector<int> res;
    while (!s.empty()) {
      pair<int, int> node = *s.begin();
      s.erase(s.begin());
      res.push_back(node.second);
      node.first--;
      pair<int, int> node2;
      if (!s.empty()) {
        node2 = *s.begin();
        s.erase(s.begin());
        res.push_back(node2.second);
        node2.first--;
      }

      if (node.first > 0) {
        s.insert(node);
      }
      if (node2.first > 0) {
        s.insert(node2);
      }
    }
    return res;
  }
};
