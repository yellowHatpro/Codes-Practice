#include <iostream>
#include <vector>

int main() {
  long long n;
  long long acc = 0;
  std::cin >> n;
  std::vector<long long> numList(n - 1);
  for (long long i = 0; i < n - 1; i++) {
    std::cin >> numList[i];
    acc += numList[i];
  }
  long long expectedSum = (n * (n + 1)) / 2;
  std::cout << expectedSum - acc;
  return 0;
}
