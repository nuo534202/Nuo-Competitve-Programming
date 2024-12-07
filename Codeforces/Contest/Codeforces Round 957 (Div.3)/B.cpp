#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int t, n, k, a[N], ans;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
 
signed main() {
	t = read();
	while (t--) {
		ans = 0;
		n = read(), k = read();
		for (int i = 1; i <= k; i++) a[i] = read();
		sort(a + 1, a + k + 1);
		for (int i = 1; i < k; i++) ans += (2 * a[i] - 1);
		printf("%lld\n", ans);
	}
	return 0;
}