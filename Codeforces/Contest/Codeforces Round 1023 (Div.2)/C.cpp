#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;
int n, k, a[N], dp[N];
string s;

void solve() {
	cin >> n >> k >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int pos1 = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0') {
			pos1 = i;
			break;
		}
	}
	if (pos1 == 0) {
		int maxm = 0;
		for (int i = 1; i <= n; i++)
			dp[i] = max(dp[i - 1] + a[i], a[i]), maxm = max(maxm, dp[i]);
		if (maxm == k) {
			cout << "Yes\n";
			for (int i = 1; i <= n; i++) cout << a[i] << " ";
			cout << "\n";
		} else cout << "No\n";
		return;
	}
	int maxm = 0, r = 1;
	for (int i = 1; i <= n; i++) dp[i] = 0;
	for (int l = 1; l <= n; l++) {
		r = l;
		while (r <= n && s[r] != '0') {
			dp[r] = max(dp[r - 1] + a[r], a[r]);
			maxm = max(maxm, dp[r]);
			r++;
		}
		l = r;
	}
	if (maxm > k) {
		cout << "No\n";
		return;
	}
	int sum = 0, pre = 0, suf = 0;
	for (int i = pos1 - 1; i >= 1; i--) {
		sum += a[i];
		pre = max(pre, sum);
	}
	sum = suf = 0;
	int pos2 = 0, pos = pos1;
	for (int i = pos1 + 1; i <= n; i++) {
		sum += a[i];
		if (suf < sum) {
			pos = i;
			suf = sum;
		}
		if (s[i] == '0') {
			pos2 = i;
			break;
		}
	}
	a[pos1] = k - suf - pre;
	if (pos2) {
		for (int i = pos + 1; i <= n; i++) {
			if (s[i] == '0') a[i] = -1e18;
		}
	}
	cout << "Yes\n";
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
