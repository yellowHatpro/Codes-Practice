#include <bits/stdc++.h>
using namespace std;
// Editorial: https://discuss.codechef.com/t/copypush-editorial/102186/2
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  while (s.size()) {
    if (s.size() % 2 != 0) {
      s.pop_back();
    } else {
      if (s.substr(0, s.size() / 2) != s.substr(s.size() / 2, s.size())) {
        cout << "NO" << endl;
        return;
      } else {
        s = s.substr(0, s.size() / 2);
      }
    }
  }
  cout << "YES\n" << endl;
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
