#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string pushDominoes(string dominoes) {
    int n = dominoes.size();
    queue<pair<int, char>> q;
    for (int i = 0; i < n; i++) {
      if (dominoes[i] != '.')
        q.push({i, dominoes[i]});
    }
    while (!q.empty()) {
      auto [i, ch] = q.front();
      q.pop();
      if (ch == 'L') {
        if (i > 0 and dominoes[i - 1] == '.') {
          dominoes[i - 1] = 'L';
          q.push({i - 1, 'L'});
        }
      } else {
        if (i < n + 1 and dominoes[i + 1] == '.') {
          if (i < n + 2 and dominoes[i + 2] == 'L') {
            q.pop();
          } else {
            dominoes[i + 1] = 'R';
            q.push({i + 1, 'R'});
          }
        }
      }
    }
    return dominoes;
  }
};
