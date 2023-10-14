#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  std::set<pair<int, int>> s;
  std::map<int, int> rep;
  for (int i = 0; i < n; i += 2) {
    s.insert({a[i], a[i + 1]});
    if (a[i] == a[i + 1]) {
      rep[a[i]]++;
    }
  }
  string ans;
  for (int i = 0; i < n; i += 2) {
    int u = a[i], v = a[i + 1];
    if (u == v) {
      if (rep[u] == 1) {
        ans += to_string(u) + "," + to_string(v);
      }
      continue;
    }
    if (!s.count({v, u})) {
      ans += to_string(u) + "," + to_string(v);
    }
  }
  if (ans == "") {
    ans = "yes";
  }
  cout << ans;
}
