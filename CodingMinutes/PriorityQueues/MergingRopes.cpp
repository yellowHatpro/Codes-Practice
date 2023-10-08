#include <bits/stdc++.h>
using namespace std;

// N different ropes and task is to join the ropes together

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int cost = 0;
  priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end());
  while (pq.size() > 1) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    cost += (a + b);
    pq.push(cost);
  }
  cout << cost << endl;
}
