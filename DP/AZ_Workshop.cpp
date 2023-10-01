#include <bits/stdc++.h>
using namespace std;

int x, k;
vector<int> t(1000), s(1000);

bool basecase = 1;

int rec(int level) {
  if (basecase) {
    return 1;
  }
  int a = rec(level + 1);
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t[i] >> s[i];
  }
  cin >> x >> k;
  cout << rec(0) << endl;
}

int main() {
  solve();
  return 0;
}
