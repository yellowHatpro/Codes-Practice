#include <bits/stdc++.h>
#include <climits>
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
#define level 18
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
#define MAXN 1000000
#define sortall(x) sort(all(x))
#define print(a)                                                               \
  for (auto i : a)                                                             \
    cout << i << " ";                                                          \
  cout << endl
#define fillv(v)                                                               \
  for (auto i : v)                                                             \
    cin >> i;

// GLOBALS

int depth[MAXN];
int parent[MAXN][18];

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

int calc(int a, int b, vector<vector<int>> &adj, vector<int> &vis) {
  if (a == b) {
    return 0;
  }
  vis[a] = 1;
  int min1 = 1e6;
  for (auto neigh : adj[a]) {
    if (!vis[neigh]) {
      min1 = min(min1, 1 + calc(neigh, b, adj, vis));
    }
  }
  vis[a] = 0;
  return min1;
}

void solve() {
  int n;
  cin >> n;
  int a, b, c;
  cin >> a >> b >> c;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int disAB = 0;
  int disBC = 0;
  int disCA = 0;
  vector<int> vis(n + 1, 0);
  disAB = calc(a, b, adj, vis);
  vis.resize(n + 1, 0);
  disBC = calc(b, c, adj, vis);
  vis.resize(n + 1, 0);
  disCA = calc(c, a, adj, vis);
  //   cout << disAB <<" "<< disBC <<" "<< disCA<<endl;
  if (disCA == disAB and disAB == disBC) {
    cout << "DRAW" << endl;
  } else if (disCA <= disBC and disCA <= disAB) {
    cout << "A" << endl;
  } else if (disAB <= disBC and disAB <= disCA) {
    cout << "B" << endl;
  } else {
    cout << "C" << endl;
  }
}

int32_t main() {
  FIO int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
