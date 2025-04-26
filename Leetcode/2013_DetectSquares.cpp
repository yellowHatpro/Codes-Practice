#include <bits/stdc++.h>
using namespace std;

class DetectSquares {
public:
  map<pair<int, int>, int> mp;
  DetectSquares() {}
  void add(vector<int> point) { mp[{point[0], point[1]}]++; }

  int count(vector<int> point) {
    int cnt = 0;
    int x = point[0];
    int y = point[1];
    for (auto &[p, second] : mp) {
      if (p.first != x and p.second != y and
          abs(p.first - x) == abs(p.second - y)) {
        int cntXY = mp[{p.first, p.second}];
        int cntX = mp[{p.first, y}];
        int cntY = mp[{x, p.second}];
        cnt += (cntXY * cntX * cntY);
      }
    }
    return cnt;
  }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
