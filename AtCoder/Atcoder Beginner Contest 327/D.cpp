// yellowhatpro
#include <bits/stdc++.h>
using namespace std;

// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// Constants
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;

// Macros
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define int long long int
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define len(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define mid(l, r) (l + (r - l) / 2)
#define sortall(x) sort(all(x))

// Type define
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef map<int, int> mii;

// Math Functions
ll LCM(int a, int b) { return ((ll)a * b) / __gcd(a, b); }

ll modpow(ll x, ll n, int m = MOD) {
  if (x == 0 && n == 0)
    return 0;
  ll res = 1;
  while (n > 0) {
    if (n % 2) {
      res = (res * x) % m;
    }
    x = (x * x) % m;
    n /= 2;
  }
  return res;
}

int CEIL(int a, int b) { return (a + b - 1) / b; }

bool dfs(int u, map<int, set<int>> &adj, int color, vector<int> &vis) {
  vis[u] = color;
  for (auto neighbour : adj[u]) {
    if (vis[neighbour] == -1) {
      if (!dfs(neighbour, adj, 1 - color, vis))
        return false;
    } else {
      if (vis[neighbour] == color)
        return false;
    }
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<int> a(m);
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  map<int, set<int>> ms;
  vector<int> x(n + 1, -1);
  for (int i = 0; i < m; i++) {
    ms[a[i]].insert(b[i]);
    ms[b[i]].insert(a[i]);
  }
  bool isBipartite = true;
  for (auto [i, j] : ms) {
    if (x[i] == -1) {
      if (!dfs(i, ms, 0, x)) {
        cout << "No" << endl;
        return;
      }
    }
  }
  cout << "Yes" << endl;
  return;
}

int32_t main() {
  FIO int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
