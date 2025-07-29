#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;
int n, p[N];

void solve() {
	cin >> n;
	int flag = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		sum += p[i];
		if (p[i] == 0) flag = 1;
	}
	if (!flag && sum >= 2 * n - 2) cout << "YES\n";
	else cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
