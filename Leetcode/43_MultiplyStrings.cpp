#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    int m = num1.size();
    int n = num2.size();
    // base cases
    if (m == 0 or n == 0 or num1 == "0" or num2 == "0") {
      return "0";
    }
    if (num1 == "1") {
      return num2;
    }
    if (num2 == "1") {
      return num1;
    }
    // What possibly could be the max size of the resulting string: m+n
    vector<int> res(m + n);
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        res[i + j] += res[i + j + 1] / 10;
        res[i + j + 1] %= 10;
      }
    }
    string ans;
    for (auto itr : res) {
      if (ans.size() == 0 and itr == 0)
        continue;
      ans += to_string(itr);
    }
    return ans;
  }
};
