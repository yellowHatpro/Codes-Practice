#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    vector<pair<int, double>> posTimePair;
    for (int i = 0; i < position.size(); i++) {
      posTimePair.push_back(
          {position[i], (double)(target - position[i]) / speed[i]});
    }
    sort(posTimePair.begin(), posTimePair.end(),
         [&](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });
    stack<double> s;
    for (auto p : posTimePair) {
      cout << "p " << p.first << " " << p.second << endl;
      if (s.empty() || s.top() < p.second) {
        s.push(p.second);
      }
    }
    return s.size();
  }
};
