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
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (cnt > 2) {
      cout << "Happy" << endl;
      return;
    }
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u') {
      cnt++;
    } else {
      cnt = 0;
    }
  }
  if (cnt > 2) {
    cout << "Happy" << endl;
    return;
  } else {
    cout << "Sad" << endl;
    return;
  }
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
