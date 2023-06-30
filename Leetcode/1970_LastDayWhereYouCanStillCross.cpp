#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> par, sz;

    DSU(int n) : par(n), sz(n, 1) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int find(int a) {
        if (par[a] == a) return a;
        return par[a] = find(par[a]);
    }

    void make(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
};

class Solution {
public:
    int latestDayToCross(int n, int m, vector<vector<int>>& cells) {
        int nm = n * m;
        auto getid = [&](int r, int c) -> int {
            return (r - 1) * m + c;
        };
        vector<bool> land(nm + 2, 0);
        land[0] = land[nm + 1] = 1;
        vector<vector<int>> adj(nm + 2);
        for (int i = 1; i <= m; i++) {
            int top = getid(1, i);
            int bottom = getid(n, i);
            adj[0].emplace_back(top);
            adj[top].emplace_back(0);
            adj[nm + 1].emplace_back(bottom);
            adj[bottom].emplace_back(nm + 1);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int a = getid(i, j);
                for (int di = -1; di <= 1; di++) {
                    int ni = i + di;
                    if (ni < 1 || n < ni) continue;
                    for (int dj = -1; dj <= 1; dj++) {
                        int nj = j + dj;
                        if (abs(di) + abs(dj) != 1 || nj < 1 || m < nj) continue;
                        adj[a].emplace_back(getid(ni, nj));
                    }
                }
            }
        }
        DSU dsu(nm + 2);
        auto makeLand = [&](int id) -> void {
            land[id] = 1;
            for (auto& x : adj[id]) {
                if (land[x]) dsu.make(id, x); 
            }
        };
        for (int i = nm - 1; i >= 0; i--) {
            makeLand(getid(cells[i][0], cells[i][1]));
            if (dsu.find(0) == dsu.find(nm + 1)) return i;
        }
        return 0;
    }
};
