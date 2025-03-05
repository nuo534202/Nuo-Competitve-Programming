#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3e5 + 10, mod = 998244353;
int n, d[N], head[N], sum[N], tot[N], f[N], num = 0;
struct edge { int to, nxt; } e[N];

void addEdge(int u, int v) { e[++num] = (edge){ v, head[u]}, head[u] = num; }

void bfs(int x) {
    queue<int> q;
    q.push(x);
    d[x] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= num; i++) e[i] = { 0, 0 };
    num = 0;
    for (int i = 1; i <= n; i++) head[i] = 0;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        addEdge(p, i);
        sum[i] = f[i] = tot[i] = 0;
    }
    bfs(1);
    for (int i = 1; i <= n; i++) sum[d[i]]++;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1 || d[i] == 2) f[i] = 1;
        if (d[i] == 2) q.push(i);
        tot[d[i]] += f[i];
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            f[v] = (tot[d[u]] - f[u]) % mod;
            tot[d[v]] += f[v];
            q.push(v);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + f[i]) % mod;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}