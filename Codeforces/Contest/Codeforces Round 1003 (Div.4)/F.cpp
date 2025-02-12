#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, a[N], num = 0, head[N];
struct edge { int to, nxt; } e[N << 1];

void addEdge(int u, int v) { e[++num] = (edge){ v, head[u] }, head[u] = num; }

void solve() {
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        map<int, int> mp;
        mp[a[i]]++;
        for (int u : g[i]) mp[a[u]]++;
        for (auto [x, y] : mp)
            if (y >= 2) ans[x] = 1;
    }
    for (int i = 1; i <= n; i++) cout << ans[i];
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}