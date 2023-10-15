#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<string> logs) {
  map<string, int> m;
  int ans = 0;
  for (auto log : logs) {
    int cnt = m[log];
    string word;
    stringstream ss(log);
    vector<string> token;
    while (ss >> word) {
      token.push_back(word);
    }
    if (token[1] == "error" and m[token[0]] == 2) {
      ans++;
      m[token[0]] = 0;
    } else if (token[1] == "success") {
      m[token[0]] = 0;
    } else
      m[token[0]]++;
  }
  return ans;
}
int main() {
  int n = 2;
  vector<string> v = {"s1 error", "s1 error", "s2 error",
                      "s1 error", "s1 error", "s2 success"};
  cout << f(n, v) << endl;
}
