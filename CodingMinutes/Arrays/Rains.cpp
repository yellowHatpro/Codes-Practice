#include <bits/stdc++.h>
using namespace std;

// Rain water trapping

int main() {
  int n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long ans = 0;
  long long maxL = v[0];
  long long maxR = v[n - 1];
  int i = 1;
  int j = n - 2;
  while (i <= j) {
    if (maxL < maxR) {
      if (v[i] < maxL) {
        ans += maxL - v[i];
      } else {
        maxL = v[i];
      }
      i++;
    } else {
      if (v[j] < maxR) {
        ans += maxR - v[j];
      } else {
        maxR = v[j];
      }
      j--;
    }
  }
  cout << ans << endl;
}
