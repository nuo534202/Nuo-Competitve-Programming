#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;
int n, k, a[N], ans = 0, flag = 0, sum = 0;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

void dfs(int cur = 1, int num = 0, int tot = 0) {
	if (num >= k) {
		ans = max(ans, tot ^ sum);
		return;
	}
	if (cur > n) return;
	dfs(cur + 1, num + 1, tot ^ a[cur]);
	dfs(cur + 1, num, tot);
}

signed main() {
	n = read(), k = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	if (k >= (n + 1) / 2) {
		k = n - k;
		flag = 1;
	}
	if (flag)
		for (int i = 1; i <= n; i++) sum ^= a[i];
	else sum = 0;
	dfs();
	printf("%lld\n", ans);
	return 0;
}