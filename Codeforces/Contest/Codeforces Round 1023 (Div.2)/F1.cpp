#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e3 + 10;
int n, a[N], dp[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], dp[i - 1] = LLONG_MAX;
	dp[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		int p = i + 1;
		for (int j = i + 1; j <= n; j++)
			if (a[j] < a[p]) p = j;
		for (int j = p; j <= n; j++)
			dp[i] = min(dp[i], dp[j] + 2 * (j - p) + (j - i) * a[p] + p - i - 1);
	}
	cout << dp[0] << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
