#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e3 + 5;
int n, k, head[N], num = 0, ans = 0;
struct edge { int to, nxt, w; } e[N << 1];

void addEdge(int u, int v, int w) {
	e[++num] = (edge){ v, head[u], w }, head[u] = num;
}

void dfs(int u, int fa, int sum, int num) {
	if (num == k) {
		ans += sum;
		return;
	}
	if (num > k) return;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to, w = e[i].w;
		if (v == fa) continue;
		dfs(v, u, sum + w, num + 1);
	}
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		addEdge(u, v, w), addEdge(v, u, w);
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, -1, 0, 0);
	}
	cout << ans << endl;
  return 0;
}
