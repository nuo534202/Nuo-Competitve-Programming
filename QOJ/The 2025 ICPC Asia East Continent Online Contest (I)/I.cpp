#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5, M = 1e5 + 5;
int n, m, V, T, head[N], vis[N], num = 0;
pair<int, int> dis[N];
struct edge { int to, nxt, w; } e[M << 1];
struct node {
	int u, num, cnt;
	bool operator< (const node& x) const {
		if (x.num == num) return x.cnt < cnt;
		return x.num < num;
	}
};

void addEdge(int u, int v, int w) {
	e[++num] = (edge){ v, head[u], w }, head[u] = num;
}

void dijsktra() {
	priority_queue<node> pq;
	for (int i = 1; i <= n; i++)
		dis[i] = make_pair(LLONG_MAX, LLONG_MAX), vis[i] = 0;
	dis[T] = make_pair(0, 0);
	pq.push((node){ T, 0, 0 });
	while (!pq.empty()) {
		int u = pq.top().u;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to, w = e[i].w;
			if (w > V) continue;
			pair<int, int> res = dis[u];
			if (res.second + w <= V) res.second += w;
			else res.first++, res.second = w;
			if (dis[v] > res) {
				dis[v] = res;
				pq.push({ v, dis[v].first, dis[v].second });
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> V >> T;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		addEdge(u, v, w), addEdge(v, u, w);
	}
	dijsktra();
	for (int i = 1; i <= n; i++) {
		if (dis[i].first == LLONG_MAX) cout << -1;
		else cout << dis[i].first + 1;
		if (i < n) cout << " ";
		else cout << endl;
	}
	return 0;
}
