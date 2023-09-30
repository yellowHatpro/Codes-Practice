#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
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

double solve() {
  int n, m;
  double res = 0;
  cin >> n >> m;
  vi nele;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    nele.push_back(x);
  }
  sort(nele.begin(), nele.end(), greater<int>());
  for (auto m : nele) {
    cout << m << " ";
  }
  cout << endl;
  int i = 0;
  for (i = 0; i < m - 1; ++i) {
    res += nele[i];
  }
  if ((n - i) % 2 == 0) {
    int mid = (n - 1 + i) / 2;

    double res2 = (double)(nele[mid] + nele[mid + 1]) / 2.0;
    return (double)res + res2;

  } else {
    int mid = (n - 1 + i) / 2.0;
    return (double)(nele[mid] + res);
  }
}

std::cout << std::fixed;
std::cout << std::setprecision(8);

int main() {

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {

    cout << "Case #" << t << ": " << solve() << endl;
  }

  return 0;
}
