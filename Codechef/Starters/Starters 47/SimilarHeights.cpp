// Editorial: https://discuss.codechef.com/t/heights-editorial/102190

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll n;
  cin >> n;
  map<ll, ll> m;
  vector<ll> v;
  ll sec = 0;
  ll ssize = 0;
  ll g = INT_MIN;
  for (ll i = 0; i < n; ++i) {

    ll x;
    cin >> x;
    v.push_back(x);
    m[x]++;
    if (v[i] > g) {
      g = v[i];
    }
  }

  for (auto i : m) {
    if (i.second == 1) {
      ssize++;
    }
    sec = max(sec, i.second);
  }

  if (ssize % 2 == 0) {
    cout << ssize / 2 << endl;
  } else {
    // The reason we are checking sec=2, is coz for sec>2, we can increase any
    // one person's height from the group (of 3 and above)
    if (m[g] == 1 && sec == 2) {
      cout << (ssize / 2) + 2 << endl;
      return;
    }
    cout << (ssize / 2) + 1 << endl;
  }
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
