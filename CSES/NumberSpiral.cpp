#include <algorithm>
#include <iostream>
int main(int argc, char *argv[]) {
  long long t;
  std::cin >> t;
  while (t--) {
    long long y, x;
    std::cin >> y >> x;
    long long ans = 0;
    long long innerSquare = std::max(y, x) - 1;
    long long lastNum = innerSquare * innerSquare;
    if (innerSquare % 2) {
      // odd
      if (x > y) {
        ans = lastNum + y;
      } else {
        ans = lastNum + y + (y - x);
      }

    } else {
      if (y > x) {
        ans = lastNum + x;
      } else {
        ans = lastNum + x + (x - y);
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}
