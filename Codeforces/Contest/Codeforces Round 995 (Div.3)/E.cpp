#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;
int n, k, a[N], b[N], p[N << 1];

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

signed main() {
	int t = read();
	while (t--) {
		n = read(), k = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		for (int i = 1; i <= n; i++) b[i] = read();
		sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
		int pp = 1, p1 = 1, p2 = 1;
		while (p1 <= n || p2 <= n) {
			if (p1 > n) p[pp++] = b[p2++];
			else if (p2 > n) p[pp++] = a[p1++];
			else if (a[p1] > b[p2]) p[pp++] = b[p2++];
			else p[pp++] = a[p1++];
		}
		int ans = 0;
		for (int i = 1; i <= 2 * n; i++) {
			int pos = lower_bound(a + 1, a + n + 1, p[i]) - a - 1;
			int idx = lower_bound(b + 1, b + n + 1, p[i]) - b;
			if (pos - idx + 1 <= k) ans = max(ans, p[i] * (n - idx + 1));
		}
		printf("%lld\n", ans);
	}
	return 0;
}
