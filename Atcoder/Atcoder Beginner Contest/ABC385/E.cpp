#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int n, ans = 0;
vector<vector<int>> g;
vector<int> deg;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	g.resize(n + 1), deg.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
		deg[u]++, deg[v]++;
	}
	for (int i = 1; i <= n; i++) {
		vector<int> v;
		for (int j : g[i]) v.push_back(deg[j]);
		sort(v.begin(), v.end(), [](int x, int y){
			return x > y;
		});
		int num = 0, tot = INT_MAX;
		for (int j : v) {
			num++, tot = min(tot, j);
			ans = max(ans, tot * num + 1);
		}
	}
	cout << n - ans << endl;
	return 0;
}
