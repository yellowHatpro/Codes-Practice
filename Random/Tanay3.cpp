#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
typedef vector<int> v;

int findMST(unordered_map<int, vector<vector<int>>> &adj, int n) {
  int ans = 0;
  vector<bool> vis(n + 1, false);
  priority_queue<v, vector<v>, greater<v>> q;
  q.push({0, 0});
  while (!q.empty()) {
    auto node = q.top();
    q.pop();
    if (vis[node[1]]) {
      continue;
    }
    ans += node[0];
    vis[node[1]] = true;
    for (auto it : adj[node[1]]) {
      if (!vis[it[0]]) {
        q.push({it[1], it[0]});
      }
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> wells(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> wells[i];
  }

  int k;
  cin >> k;
  vector<vector<int>> pipes(k, vector<int>(3, 0));
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> pipes[i][j];
    }
  }

  unordered_map<int, vector<vector<int>>> adj;
  for (auto it : pipes) {
    adj[it[0]].push_back({it[1], it[2]});
    adj[it[1]].push_back({it[0], it[2]});
  }
  for (int i = 0; i < wells.size(); i++) {
    adj[0].push_back({i + 1, wells[i]});
    adj[i + 1].push_back({0, wells[i]});
  }
  cout << findMST(adj, n) << endl;
  return 0;
}
