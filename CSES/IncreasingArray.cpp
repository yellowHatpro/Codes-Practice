#include <iostream>
#include <vector>
int main() {
  long long n;
  std::cin >> n;
  long long res = 0;
  std::vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    std::cin >> v[i];
    if (i != 0) {
      if (v[i] < v[i - 1]) {
        res += v[i - 1] - v[i];
        v[i] = v[i - 1];
      }
    }
  }
  std::cout << res;
  return 0;
}
