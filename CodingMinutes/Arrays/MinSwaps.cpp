#include <bits/stdc++.h>
using namespace std;

int countMinSwaps(vector<int> &v) {
  int ans = 0;
  int n = v.size();
  vector<pair<int, int>> actualPositions(n);
  for (int i = 0; i < n; i++) {
    actualPositions[i].first = v[i];
    actualPositions[i].second = i;
  }
  sort(actualPositions.begin(), actualPositions.end());
  vector<bool> visited(n, 0);
  for (int i = 0; i < n; i++) {
    // element already visited or is at right position
    if (visited[i] or actualPositions[i].second == i) {
      continue;
    }
    // element visiting for the first time
    else {
      int node = i;
      int cycle = 0;
      while (!visited[node]) {
        visited[node] = 1;
        int next_node = actualPositions[node].second;
        node = next_node;
        cycle++;
      }
      ans += (cycle - 1);
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  cout << countMinSwaps(v) << endl;
  return 0;
}
