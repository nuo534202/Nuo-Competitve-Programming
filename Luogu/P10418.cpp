#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;
int n;
struct edge { int u, v, w; } e[N];

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[i + 1].push_back(v);
        g[u].push_back(v);
        e[i] = (edge){ i + 1, u, v };
    }
    for (int i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end(), greater<int>());
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (g[i].size() >= 3) ans = max(ans, g[i][0] + g[i][1] + g[i][2]);
    for (int i = 1; i < n; i++) {
        if (g[e[i].u].size() >= 2 && g[e[i].v].size() >= 2) {
            int res = e[i].w;
            if (g[e[i].u][0] == e[i].w) res += g[e[i].u][1];
            else res += g[e[i].u][0];
            if (g[e[i].v][0] == e[i].w) res += g[e[i].v][1];
            else res += g[e[i].v][0];
            ans = max(ans, res);
        }
    }
    cout << ans << endl;
    return 0;
}
