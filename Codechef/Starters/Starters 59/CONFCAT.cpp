#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define mem(a, val) memset(a, val, sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  int maxi = 0;
  for (int i = 0; i < n; ++i) {
    if (c[i] > c[maxi]) {
      maxi = i;
    }
  }
  if (maxi == 0) {
    cout << -1 << endl;
    return;
  }
  cout << maxi << endl;
  for (int i = 0; i < maxi; ++i) {
    cout << c[i] << " ";
  }
  cout << n - maxi << endl;
  for (int i = maxi; i < n; i++) {
    cout << c[i] << " ";
  }
  cout << endl;
  return;
}

int main() {
  std::ios::sync_with_stdio(false);
  int T;
  cin >> T;
  // cin.ignore(); must be there when using getline(cin, s)
  while (T--) {
    solve();
  }
  return 0;
}
