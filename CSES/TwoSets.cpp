#include <iostream>
int main(int argc, char *argv[]) {
  long long n;
  std::cin >> n;
  // its an easy problem tbh
  long long totalSum = (n * (n + 1)) / 2;
  if (totalSum % 2) {
    // odd
    std::cout << "NO";
    return 0;
  }
  std::cout << "YES\n";
  if (n % 2) {
    // no. of elements are odd, then in one set keep 1 , 2 and in another
    // keep 3. This way, we are n (odd)- 3 (odd ) elements, thus now we have
    // even elements. So we can arrange them easily
    std::cout << (int)n / 2 + 1 << "\n";
    std::cout << "1 2 ";
    for (int i = 0; i < (n - 3) / 4; i++) {
      std::cout << i + 4 << " " << n - i << " ";
    }
    std::cout << "\n";
    std::cout << (int)n / 2 << "\n";
    std::cout << "3 ";
    for (int i = (n - 3) / 4; i < (n - 3) / 2; i++) {
      std::cout << i + 4 << " " << n - i << " ";
    }
  } else {
    std::cout << n / 2 << "\n";
    for (int i = 0; i < n / 4; i++) {
      std::cout << i + 1 << " " << n - i << " ";
    }
    std::cout << "\n";
    std::cout << n / 2 << "\n";
    for (int i = n / 4; i < n / 2; i++) {
      std::cout << i + 1 << " " << n - i << " ";
    }
  }
  return 0;
}
