#include <iostream>

#define int long long

void useDerangement(const int N, const int M) {
  // D_i = i * D_{i-1} + (-1)^i
  int D = 1 % M; // D_0
  for (int i = 1; i <= N; ++i) {
    D = (D * (i % M)) % M;             // i * D_{i-1} mod M
    D = (D + (i % 2 ? M - 1 : 1)) % M; // adding (-1)^i mod M
    std::cout << D << (i == N ? '\n' : ' ');
  }
}

int32_t main() {
  int N{0}, M{0};
  std::cin >> N >> M;
  useDerangement(N, M);
}
