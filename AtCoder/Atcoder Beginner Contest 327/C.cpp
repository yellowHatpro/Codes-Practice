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

void solve() {
  vector<vector<int>> sudoku;
  for (int i = 0; i < 9; i++) {
    vector<int> v;
    for (int j = 0; j < 9; j++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    sudoku.push_back(v);
  }

  for (int i = 0; i < 9; i++) {
    set<int> s, r;
    for (int j = 0; j < 9; j++) {
      if (s.find(sudoku[i][j]) != s.end()) {
        cout << "No" << endl;
        return;
      }
      s.insert(sudoku[i][j]);
      if (r.find(sudoku[j][i]) != r.end()) {
        cout << "No" << endl;
        return;
      }
      r.insert(sudoku[j][i]);
    }
  }
  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 9; j += 3) {
      set<int> s;
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          if (s.find(sudoku[i + k][j + l]) != s.end()) {
            cout << "No" << endl;
            return;
          }
          s.insert(sudoku[i + k][j + l]);
        }
      }
    }
  }
  cout << "Yes" << endl;
}

int32_t main() {
  FIO int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
