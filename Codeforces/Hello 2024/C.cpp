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
#define print(a)                                                               \
  for (auto i : a)                                                             \
    cout << i << " ";                                                          \
  cout << endl
#define fillv(v)                                                               \
  for (auto i : v)                                                             \
    cin >> i;

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

// DP solution will give MLE here
//  TODO: Come back when you learn segment tree, check the editorial:
//  https://codeforces.com/blog/entry/124220
int f(int s, int t, vector<int> &a, vector<vector<vector<int>>> &dp, int i,
      int n, int penA, int penB) {
  if (i == n) {
    return penA + penB;
  }
  if (dp[i][penA][penB] != -1) {
    return dp[i][penA][penB];
  }
  int cntS = penA;
  int cntT = penB;
  if (s != 0 and s < a[i]) {
    cntS++;
  }
  if (t != 0 and t < a[i]) {
    cntT++;
  }
  int inS = f(a[i], t, a, dp, i + 1, n, (s != 0 and s < a[i]) ? penA + 1 : penA,
              penB);
  int inT = f(s, a[i], a, dp, i + 1, n, penA,
              (t != 0 and t < a[i]) ? penB + 1 : penB);
  return dp[i][penA][penB] = min(inS, inT);
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
  cout << f(0, 0, a, dp, 0, n, 0, 0) << endl;
}

void greedy() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> s, t;
  int ans = 0;
  for (auto itr : a) {
    if (s.empty()) {
      s.push_back(itr);
    } else if (t.empty()) {
      if (itr <= s.back()) {
        s.push_back(itr);
      } else {
        t.push_back(itr);
      }
    } else {
      // make t = array having smaller back element
      if (s.back() < t.back()) {
        swap(s, t);
      }
      if (itr <= t.back()) {
        t.push_back(itr);
      } else if (itr <= s.back()) {
        s.push_back(itr);
      } else {
        t.push_back(itr);
        ans++;
      }
    }
  }
  cout << ans << endl;
}

int32_t main() {
  FIO int t = 1;
  cin >> t;
  while (t--) {
    // solve();
    greedy();
  }
  return 0;
}
