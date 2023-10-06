#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct Coordinate {
  string name;
  int x;
  int y;
};

int dist(Coordinate ij) { return ij.x * ij.x + ij.y * ij.y; }

int main() {

  int n, k;
  cin >> n >> k;
  vector<Coordinate> v(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int x;
    cin >> x;
    int y;
    cin >> y;
    Coordinate ij = Coordinate(s, x, y);
    v[i] = ij;
  }
  // defining custom comparator for max heap
  auto cmp = [](Coordinate a, Coordinate b) {
    return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
  };
  // max heap
  priority_queue<Coordinate, vector<Coordinate>, decltype(cmp)> pq(
      v.begin(), v.begin() + k);
  for (int i = k; i < n; i++) {
    Coordinate curr = v[i];
    if (dist(pq.top()) > dist(curr)) {
      pq.pop();
      pq.push(curr);
    }
  }

  return 0;
}
