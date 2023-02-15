#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b), adj[b].push_back(a);
    }

    std::map<pair<int, int>, std::set<int>> tri;

    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        tri[{a, b}].insert(c);
    }

    std::queue<pair<pair<int, int>, int>> fri;
    std::vector<std::vector<bool>> vis(n, std::vector<bool>(n, false));

    fri.push({{0, 0}, 0});
    int ans = -1;
    std::vector<std::vector<int>> par(n, std::vector<int>(n, -1));
    std::vector<int> path;
    vis[0][0] = true;
    while (!fri.empty()) {
        auto [pat, len] = fri.front();
        //    cout << pat.first << ' ' << pat.second << '\n';
        if (pat.second == n - 1) {
            for (int i = pat.first, j = pat.second; i != -1;) {
                path.push_back(j + 1);
                int k = par[i][j];
                //     cout << i << ' ' << j << ' ' << k << '\n';
                j = i, i = k;
            }
            ans = len;
            break;
        }
        fri.pop();
        for (int ne : adj[pat.second]) {
            if (vis[pat.second][ne] or tri[pat].count(ne)) {
                continue;
            }
            fri.push({{pat.second, ne}, len + 1});
            par[pat.second][ne] = pat.first;
            vis[pat.second][ne] = true;
        }
    }
    reverse(path.begin(), path.end());
    cout << ans;
    cout << endl;
    for (auto i : path) {
        cout << i << ' ';
    }
    return 0;
}