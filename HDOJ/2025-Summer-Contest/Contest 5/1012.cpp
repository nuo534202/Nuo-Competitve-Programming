#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;
int n, a[N], b[N], A[N], B[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
		A[i] = a[i] - b[i], B[i] = a[i] + b[i];
	sort(A + 1, A + n + 1), sort(B + 1, B + n + 1);
	int ans = LLONG_MAX;
	for (int i = 2; i <= n; i++)
		ans = min({ ans, A[i] - A[i - 1], B[i] - B[i - 1] });
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
