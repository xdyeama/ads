#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int res = 1e9;

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);
    vector<bool> visss(n, false);

    for (int i = 0; i < m; i++) {
        int u, v, l; cin >> u >> v >> l;
        u--; v--;
        if (v != u) {
            g[u].push_back(make_pair(v, l));
            g[v].push_back(make_pair(u, l));
        }
    }

    for (int i = 0; i < n; i++) {
        if (!viss[i]) {
            viss[i] = true;
            int mx = -1;
            for (auto el : g[i]) {
                int len = el.second;
                mx = max(len, mx);
            }
            if (mx != -1)
                res = min(res, mx - 1);
        }
    }

    cout << res << '\n';

    return 0;
}
