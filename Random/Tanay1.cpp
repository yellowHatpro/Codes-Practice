#include <bits/stdc++.h>
using namespace std;

void fn() {
  string s, p;
  cin >> s >> p;
  int m = s.length(), n = p.length();
  vector<bool> curr(m + 1, 0);
  curr[0] = 1;
  for (int j = 1; j <= n; j++) {
    bool pre = curr[0];
    curr[0] = curr[0] && p[j - 1] == '*';
    for (int i = 1; i <= m; i++) {
      bool temp = curr[i];
      if (p[j - 1] != '*')
        curr[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
      else
        curr[i] = curr[i - 1] || curr[i];
      pre = temp;
    }
  }
  if (curr[m]) {
    cout << "Match";
  } else {
    cout << "Does not match";
  }
}
