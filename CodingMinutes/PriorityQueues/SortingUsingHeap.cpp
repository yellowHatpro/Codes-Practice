#include <bits/stdc++.h>
#include <functional>
#include <queue>
using namespace std;

int main() {
  vector<int> arr = {10, 15, 20, 13, 6, 90};
  int n = arr.size();
  priority_queue<int> max_heap; // max heap by default (max element at top)
  for (int itr : arr) {
    max_heap.push(itr);
  }
  while (!max_heap.empty()) {
    cout << max_heap.top() << endl;
    max_heap.pop();
  }
  priority_queue<int, vector<int>, greater<int>> min_heap;

  for (int itr : arr) {
    min_heap.push(itr);
  }
  return 0;
}
