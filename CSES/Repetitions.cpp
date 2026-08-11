#include <algorithm>
#include <iostream>

int main() {
  std::string s;
  std::cin >> s;
  long long cnt = 1;
  long long maxCnt = 1;
  for (long long i = 0; i < s.size() - 1; i++) {
    if (s[i] == s[i + 1]) {
      cnt++;
    } else {
      cnt = 1;
    }
    maxCnt = std::max(maxCnt, cnt);
  }
  std::cout << maxCnt;
  return 0;
}
