#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;
int n, x, y, a[N], sum;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

signed main() {
	int t = read();
	while (t--) {
		n = read(), x = read(), y = read(), sum = 0;
		for (int i = 1; i <= n; i++) a[i] = read(), sum += a[i];
		sort(a + 1, a + n + 1);
		int ans = 0;
		for (int l = 1; l <= n; l++) {
			if (sum - a[l] < x) break;
			int L = lower_bound(a + 1, a + n + 1, sum - a[l] - y) - a;
			int R = upper_bound(a + 1, a + n + 1, sum - a[l] - x) - a - 1;
			if (L <= R && R > l) ans += min(R - L + 1, R - l);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
