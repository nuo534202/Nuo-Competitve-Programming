#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 5, mod = 998244353;
int n, a[N];

void solve() {
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	int l = n, r = 1;
	for (int i = 1; i <= n; i++)
		if (a[i] > 0) {
			l = i;
			break;
		}
	for (int i = n; i; i--) {
		if (a[i] > 0) {
			r = i;
			break;
		}
	}
	int maxm = a[l], minm = a[l];
	for (int i = l; i <= r; i++)
		if (a[i]) maxm = max(maxm, a[i]), minm = min(minm, a[i]);
	int res;
	if (l == n && r == 1) {
		res = ((n + 1) * n / 2 % mod) * ((n - maxm + 1) * (minm + n + 1) % mod) % mod;
	}
	else {
		res = (l * (n - r + 1) % mod) * ((n - maxm + 1) * (minm + n + 1) % mod) % mod;
	}
	cout << sum << " " << res % mod << '\n';
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
