#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, w[505], h[505], k;

bool check(int x) {
	ll tot = 0;
	for (int i = 1; i <= n; i++)
		tot += 1LL * (w[i] / x) * (h[i] / x);
	return tot >= k;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> h[i];
	cin >> k;
	int l = 1, r = 10000;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid;
		else r = mid;
	}
	cout << l << endl;
	return 0;
}
