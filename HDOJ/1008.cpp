#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, a[N];

void solve() {
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int now = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > now) ans += (a[i] - now) * 6;
		if (a[i] < now) ans += (now - a[i]) * 4;
		now = a[i], ans += 5;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	while (1) {
		cin >> n;
		if (!n) break;
		solve();
	}
	return 0;
}
