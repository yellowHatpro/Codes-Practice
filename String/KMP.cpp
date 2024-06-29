#include <bits/stdc++.h>
using namespace std;

class KMP {
public:
  vector<int> reset;
  int N;
  KMP(int n) {
    this->N = n;
    reset.resize(N, 0);
  }
  void preprocess(string pat) {
    int i = 0, j = -1;
    reset[0] = j;
    while (j >= 0 and pat[i] != pat[j]) {
    }
  }
};
