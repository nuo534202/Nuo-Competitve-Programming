#include <bits/stdc++.h>
using namespace std;

#define int long long 

int n, k;

void solve() {
	cin >> n >> k;
	int maxm = 0;
	for (int i = 0; i < n; i++) maxm += i * (n - i - 1);
	if (maxm < k - 1) {
		cout << "No\n";
		return;
	}
	k = maxm - k;
	vector<vector<int>> g(n + 1);
	int h = n - 1;
	for (int i = n - 1; i; i--)
		if (k >= i * (i - 1) / 2) {
			g[h - i].push_back(h);
			h--;
			k -= i * (i - 1) / 2;
		}
	for (int i = 0; i < h; i++) g[i].push_back(i + 1);
	cout << "Yes\n";
	for (int i = 0; i < n; i++) {
		for (int v : g[i]) cout << i + 1 << " " << v + 1 << "\n"; 
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
