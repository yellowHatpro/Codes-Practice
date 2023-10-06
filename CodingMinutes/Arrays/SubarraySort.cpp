#include <bits/stdc++.h>
using namespace std;

bool outOfOrder(vector<int> &v, int idx) {
  if (idx == 0)
    return v[0] > v[1];
  if (idx == v.size() - 1)
    return v[v.size() - 1] < v[v.size() - 2];
  return v[idx] > v[idx + 1] or v[idx] < v[idx - 1];
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int smallestOutOfOrderElement = INT_MAX;
  int largestOutOfOrderElement = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (outOfOrder(v, i)) {
      smallestOutOfOrderElement = min(smallestOutOfOrderElement, v[i]);
      largestOutOfOrderElement = max(largestOutOfOrderElement, v[i]);
    }
  }
  int l = 0;
  int r = n - 1;
  while (v[l] <= smallestOutOfOrderElement) {
    l++;
  }
  while (v[r] >= largestOutOfOrderElement) {
    r--;
  }
  cout << l << " and " << r << endl;
  return 0;
}
