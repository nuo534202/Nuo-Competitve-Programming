#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 10, M = 1e6 + 10;
int n, m, s, t, head[N], d[N], vis[N], ans[2], num = 1;
struct edge { int to, nxt, cap; } e[M];
 
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
 
void add(int u, int v, int cap) {
	e[++num] = (edge){ v, head[u], cap }, head[u] = num;
	e[++num] = (edge){ u, head[v], 0 }, head[v] = num;
}
 
bool bfs() {
	memset(d, 0, sizeof(d)); queue<int> q; q.push(s); d[s] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to, cap = e[i].cap;
			if (!d[v] && cap) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	return d[t];
}
 
int dinic(int cur, int flow) {
	if (cur == t) return flow;
	int res = flow;
	for (int i = head[cur]; i; i = e[i].nxt) {
		if (!res) return flow;
		int v = e[i].to, cap = e[i].cap;
		if (!cap) continue;
		if (d[v] != d[cur] + 1) continue;
		int k = dinic(v, min(res, cap));
		if (!k) d[v] = 0;
		res -= k, e[i].cap -= k, e[i ^ 1].cap += k;
	}
	return flow - res;
}
 
void dfs(int u, int x) {
	ans[x] += x ? (u <= n + 1) : (u > n + 1);
	vis[u] = 1;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (vis[v] || e[i].cap != x) continue;
		dfs(v, x);
	}
}
 
int main() {
	int T = read();
	while (T--) {
		n = read(), m = read();
		num = 1, ans[0] = ans[1] = 0;
		for (int i = 0; i <= 2 * n + 2; i++) head[i] = vis[i] = 0;
		s = 1, t = 2 * n + 2;
		for (int i = 1; i <= m; i++) {
			int u = read(), v = read();
			add(u + 1, v + n + 1, 1);
		}
		for (int i = 1; i <= n; i++) add(s, i + 1, 1);
		for (int i = 1; i <= n; i++) add(i + n + 1, t, 1);
		int maxflow = 0, flow = 0;
		while (bfs()) { while(flow = dinic(s, INT_MAX)) maxflow += flow; }
		dfs(t, 0), dfs(s, 1);
		printf("%lld\n", 1LL * (ans[0] - 1) * (ans[1] - 1)); // 要除去 s 和 t 节点
	}
	return 0;
}
