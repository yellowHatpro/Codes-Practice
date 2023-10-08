#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

// merge n sorted arrays to one

vector<int> mergeKArrays(vector<vector<int>> &vv) {
  int k = vv.size();
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
  vector<int> res;
  for (int i = 0; i < k; i++) {
    pq.push({vv[i][0], i, 0});
  }
  // start popping
  while (!pq.empty()) {
    auto ele = pq.top();
    pq.pop();
    res.push_back(ele[0]);
    int next_ele = vv[ele[1]][ele[2] + 1];
    if (ele[2] + 1 < vv[ele[1]].size()) {
      pq.push({next_ele, ele[1], ele[2] + 1});
    }
  }
  return res;
}

int main() {
  vector<vector<int>> input = {
      {1, 2, 3, 4, 5, 6, 7}, {4, 6, 9, 23, 24}, {1, 5, 9, 10}};
  auto res = mergeKArrays(input);
  for (auto itr : res) {
    cout << itr << " ";
  }
  return 0;
}
