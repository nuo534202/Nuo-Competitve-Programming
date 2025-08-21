#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, ans = INT_MIN;
	cin >> n;
	vector<int> a(n + 1), dp(n + 1, INT_MIN), lst(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (dp[i - 1] >= 0) dp[i] = dp[i - 1] + a[i], lst[i] = i - 1;
		else dp[i] = a[i], lst[i] = i;
		ans = max(ans, dp[i]);
	}
	int r = 1;
	for (int i = 1; i <= n; i++)
		if (dp[i] == ans) {
			r = i;
			break;
		}
	int l = r;
	while (lst[l] && lst[l] != l) l = lst[l];
	cout << ans << " " << l << " " << r << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case " << i << ":\n";
		solve();
		if (i < T) cout << "\n";
	}
  return 0;
}
