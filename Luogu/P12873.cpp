#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e3 + 5;
int n, head[N], dis[N], num = 0;
struct edge { int to, nxt; } e[N << 1];

void addEdge(int u, int v) {
	e[++num] = (edge){ v, head[u] }, head[u] = num;
}

void dfs(int u, int fa) {
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		dis[v] = dis[u] + 1;
		dfs(v, u);
	}
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		addEdge(u, v), addEdge(v, u);
	}
	dfs(1, 0);
	int pos = 0, maxDis = 0;
	for (int i = 1; i <= n; i++)
		if (maxDis < dis[i]) maxDis = dis[i], pos = i;
	for (int i = 1; i <= n; i++)
		dis[i] = 0;
	dfs(pos, 0);
	pos = 0, maxDis = 0;
	for (int i = 1; i <= n; i++)
		if (maxDis < dis[i]) maxDis = dis[i], pos = i;
	cout << maxDis / 2 * 2 << endl;
	return 0;
}
