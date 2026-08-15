#include <iostream>
int main(int argc, char *argv[]) {
  long long n;
  std::cin >> n;
  for (long long k = 1; k <= n; k++) {
    // total positions
    long long totalPositions = k * k * (k * k - 1) / 2;
    // total attacking positions
    long long attackingPositions = 4 * (k - 1) * (k - 2);
    std::cout << totalPositions - attackingPositions << "\n";
  }
  return 0;
}
