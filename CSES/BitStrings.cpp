#include <iostream>

#define MOD 1000000007

long long modpow(long long x, long long y) {
  if (y == 0) {
    return 1;
  }
  long long half = modpow(x, y / 2) % MOD;
  if (y % 2) {
    return (x * (half * half) % MOD) % MOD;
  } else {
    return (half * half) % MOD;
  }
}

int main(int argc, char *argv[]) {
  long long n;
  std::cin >> n;
  std::cout << modpow(2, n);
  return 0;
}
