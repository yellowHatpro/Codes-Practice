#include <iostream>
int main(int argc, char *argv[]) {
  long long n;
  std::cin >> n;
  if (n <= 3 and n > 1) {
    std::cout << "NO SOLUTION";
  } else {
    for (long long i = 2; i <= n; i += 2) {
      std::cout << i << " ";
    }
    for (long long i = 1; i <= n; i += 2) {
      std::cout << i << " ";
    }
  }
  return 0;
}
