#include <bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big, string small) {
  // store the occurrences in the result vector
  vector<int> result = {};
  int index = big.find(small);
  if (index != -1) {
    result.push_back(index);
    while (index != -1) {
      index = big.find(small, index + 1);
      if (index != -1) {
        result.push_back(index);
        continue;
      } else
        break;
    }
    return result;
  }
}

int main() {
  string s;
  getline(cin, s, '.'); // 3rd parameter in getline function is a delimiter

  return 0;
}
