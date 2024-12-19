#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, x, y, head[N], d[N], dis[N], vis[N], num = 0;
struct edge { int to, nxt, w; } e[N << 1];
struct node { int id, dis; };

void addEdge(int u, int v, int w) { e[++num] = (edge){ v, head[u], w }, head[u] = num; }

void dfs(int u) {
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to, w = e[i].w;
		if (!d[v]) {
			d[v] = d[u] + w;
			dfs(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		addEdge(u, v, 1), addEdge(v, u, 2);
	}
	cin >> x >> y;
	d[1] = 1;
	dfs(1);
	int maxDepth = 0, maxWidth = 0;
	for (int i = 1; i <= n; i++) vis[d[i]]++, maxDepth = max(maxDepth, d[i]);
	for (int i = 1; i <= n; i++) maxWidth = max(maxWidth, vis[i]);
	cout << maxDepth << '\n' << maxWidth << '\n';
	memset(d, 0, sizeof(d));
	d[x] = 1;
	dfs(x);
	cout << d[y] - 1;
	return 0;
}
