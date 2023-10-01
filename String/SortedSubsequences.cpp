#include <bits/stdc++.h>
using namespace std;

void sortedSubsequences(string s, string o, vector<string> &v) {
  if (s.empty()) {
    v.push_back(o);
    return;
  }

  sortedSubsequences(s.substr(1), o + s[0], v);
  sortedSubsequences(s.substr(1), o, v);
  return;
}

bool compare(string s, string t) {
  if (s.size() == t.size()) {
    return s < t; // if same length then lexicographically sort
  }
  return s.size() < t.size(); // else size
}

int main() {
  string s;
  cin >> s;
  string output = "";
  vector<string> v;
  sortedSubsequences(s, output, v);
  sort(v.begin(), v.end(), compare);
  for (auto itr : v) {
    cout << itr << endl;
  }
  return 0;
}
