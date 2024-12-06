#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int N = 1e6 + 10, mod = 1e9 + 7;
int r, c, f[N << 1], vis[N << 1];
string s[N];
 
int qpow(int x, int k) {
	int res = 1LL;
	while (k) {
		if (k & 1) res = res * x % mod;
		x = x * x % mod;
		k >>= 1;
	}
	return res % mod;
}
 
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
 
void solve() {
	cin >> r >> c;;
	vector<vector<int>> v(c + 1);
	for (int i = 1; i <= r; i++) {
		cin >> s[i], s[i] = " " + s[i];
		for (int j = 1; j <= c; j++) {
			if (s[i][j] == '1') v[j].push_back(i);
		}
	}
	if ((c & 1) && v[(c + 1) >> 1].size() > 1) {
		cout << 0 << '\n';
		return;
	}
	for (int i = 1; i <= c / 2; i++) {
		if (v[i].size() + v[c - i + 1].size() > 2) {
			cout << 0 << '\n';
			return;
		}
	}
	for (int i = 1; i <= 2 * r; i++) f[i] = i, vis[i] = 0;
	for (int i = 1; i <= c / 2; i++) {
		if (v[i].size() + v[c - i + 1].size() <= 1) continue;
		if (v[i].size() == 2) {
			int u1 = v[i][0], u2 = v[i][1];
			f[find(u1 + r)] = find(u2);
			f[find(u2 + r)] = find(u1);
		} else if (v[c - i + 1].size() == 2) {
			int u1 = v[c - i + 1][0], u2 = v[c - i + 1][1];
			f[find(u1 + r)] = find(u2);
			f[find(u2 + r)] = find(u1);
		} else {
			int u1 = v[i][0], u2 = v[c - i + 1][0];
			f[find(u1)] = find(u2);
			f[find(u1 + r)] = find(u2 + r);
		}
	}
	for (int i = 1; i <= r; i++) {
		if (find(i) == find(i + r)) {
			cout << 0 << '\n';
			return;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 2 * r; i++) {
		int f = find(i);
		if (!vis[f]) cnt++;
		vis[f] = 1;
	}
	cout << qpow(2, cnt / 2) << '\n';
}
 
signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) solve();
	return 0;
}
