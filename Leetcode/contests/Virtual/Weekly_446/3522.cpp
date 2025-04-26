#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long calculateScore(vector<string> &instructions, vector<int> &values) {
    int n = instructions.size();
    long long ans = 0;
    vector<int> visited(n, 0);
    int i = 0;
    while (i < n and i >= 0) {
      if (visited[i]) {
        return ans;
      }
      visited[i] = 1;
      if (instructions[i] == "jump") {
        i += values[i];
      } else {
        ans += values[i];
        i++;
      }
    }
    return ans;
  }
};
