#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, a, b[N], vis[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a, vis[a] = i;
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	int ans = 0;
	vis[0] = -1;
	for (int i = 1; i <= n; i++) {
		if (vis[b[i]] != vis[b[i - 1]] + 1) ans++;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
