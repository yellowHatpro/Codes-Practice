#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

bool checkIfBothPilesEmptyUgly(long long a, long long b) {
  long long x = a % 3;
  long long y = b % 3;
  if (std::abs(x - y) <= 1) {
    if (std::max(a, b) > 2 * std::min(a, b)) {
      return false;
    }
    if ((x == 2 and y == 1) or (x == 1 and y == 2)) {
      return true;
    } else if (x == y and (a % 3 == 0) and (b % 3 == 0)) {
      return true;
    }
  }
  return false;
}

bool checkIfBothPilesEmpty(long long a, long long b) {
  return (a + b) % 3 == 0 and std::max(a, b) <= 2 * std::min(a, b);
}

bool checkIfBothPilesEmptyDP(long long a, long long b,
                             std::vector<std::vector<long long>> &v) {
  if (a == b and a == 0) {
    return true;
  }
  if (a < 0 or b < 0) {
    return false;
  }

  if (v[a][b] != -1) {
    return v[a][b];
  }
  int i = checkIfBothPilesEmptyDP(a - 1, b - 2, v);
  int j = checkIfBothPilesEmptyDP(a - 2, b - 1, v);
  v[a][b] = i || j;
  return v[a][b];
}

int main(int argc, char *argv[]) {
  int t;
  std::cin >> t;
  while (t--) {
    long long a, b;
    std::cin >> a >> b;
    // std::vector<std::vector<long long>> v(a + 1,
    //                                     std::vector<long long>(b + 1, -1));
    // if (checkIfBothPilesEmptyDP(a, b, v)) {
    if (checkIfBothPilesEmpty(a, b)) {

      std::cout << "YES" << "\n";
    } else {
      std::cout << "NO" << "\n";
    }
  }
  return 0;
}
