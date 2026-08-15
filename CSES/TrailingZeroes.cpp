#include <iostream>

long long numOf5(long long n) {
  if (n / 5 == 0) {
    return 0;
  }
  return (long long)(n / 5) + numOf5((long long)n / 5);
}

int main(int argc, char *argv[]) {
  long long n;
  std::cin >> n;
  std::cout << numOf5(n);
  return 0;
}
