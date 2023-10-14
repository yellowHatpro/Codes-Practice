#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  cin >> c;
  int n = 12;
  std::vector<int> a(12);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int min_val = *min_element(a.begin(), a.end());
  for (auto &i : a) {
    i -= min_val;
  }
  int ans = 0;
  if (c == 'I') {
    for (int i = 0; i < n; i++) {
      a[i] += 4;
      if (*min_element(a.begin(), a.end()) != 0) {
        ans = 4;
      }
      a[i] -= 4;
    }
    for (int i = 0; i + 3 < n; i++) {
      int mval = *max_element(a.begin() + i, a.begin() + i + 4);
      bool p = true;
      for (int j = 0; j < i; j++) {
        p &= (a[j] > mval);
      }
      for (int j = i + 4; j < n; j++) {
        p &= (a[j] > mval);
      }
      if (p) {
        ans = max(ans, 1);
      }
    }
  }
  if (c == 'O') {
    for (int i = 0; i + 1 < n; i++) {
      int mval = *max_element(a.begin() + i, a.begin() + i + 2);
      bool one = true, tw = true;
      for (int j = 0; j < i; j++) {
        one &= (a[j] > mval);
        tw &= (a[j] > mval + 1);
      }
      for (int j = i + 2; j < n; j++) {
        one &= (a[j] > mval);
        tw &= (a[j] > mval + 1);
      }
      if (one) {
        ans = max(ans, 1);
      }
      if (tw) {
        ans = max(ans, 2);
      }
    }
  }
  cout << ans << endl;
}
