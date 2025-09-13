#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e3 + 5, M = 1e4 + 5, inf = 1e18;
int n, m, head[N], d[N], f[N], g[N], num = 0;
struct Edge { int to, nxt, w; } e[N << 1];
struct Trans { int u, v; } trans[M];

void addEdge(int u, int v, int w) {
	e[++num] = (Edge){ v, head[u], w }, head[u] = num;
}

void dfs1(int u, int fa) {
	f[u] = d[u];
	for (int i = head[u]; i; i = e[i].nxt)
		if (e[i].to != fa) {
			dfs1(e[i].to, u);
			f[u] = min(f[u], f[e[i].to] + e[i].w);
		}
}

void dfs2(int u, int fa, int w) {
	g[u] = f[u] = min(f[u], w);
	for (int i = head[u]; i; i = e[i].nxt)
		if (e[i].to != fa)
			dfs2(e[i].to, u, f[u] + e[i].w);
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		addEdge(u, v, w), addEdge(v, u, w);
	}
	for (int i = 1; i <= m; i++)
		cin >> trans[i].u >> trans[i].v;
	for (int i = 1; i <= n; i++)
		d[i] = inf;
	d[1] = 0;
	for (int k = 0; k <= n; k++) {
		dfs1(1, 0), dfs2(1, 0, inf);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans += g[i], d[i] = g[i];
		cout << ans << "\n";
		for (int i = 1; i <= m; i++) {
			d[trans[i].u] = min(d[trans[i].u], g[trans[i].v]);
			d[trans[i].v] = min(d[trans[i].v], g[trans[i].u]);
		}
	}
	return 0;
}
