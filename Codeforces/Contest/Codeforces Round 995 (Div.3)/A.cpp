#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N], b[N], n;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int main() {
	int t = read();
	while (t--) {
		n = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		for (int i = 1; i <= n; i++) b[i] = read();
		int ans = 0;
		for (int i = 1; i < n; i++) ans += a[i] - b[i + 1] > 0 ? a[i] - b[i + 1] : 0;
		ans += a[n];
		printf("%d\n", ans);
	}
	return 0;
}
