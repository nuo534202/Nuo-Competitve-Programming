#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int n, m, k, a[N], q, vis[N];

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int main() {
	int t = read();
	while (t--) {
		n = read(), m = read(), k = read();
		for (int i = 1; i <= n; i++) vis[i] = 1;
		for (int i = 1; i <= m; i++) a[i] = read();
		for (int i = 1; i <= k; i++) q = read(), vis[q] = 0;
		if (k < n - 1) {
			for (int i = 1; i <= m; i++) putchar('0');
			puts("");
			continue;
		}
		if (k == n) {
			for (int i = 1; i <= m; i++) putchar('1');
			puts("");
			continue;
		}
		for (int i = 1; i <= m; i++) {
			if (vis[a[i]]) putchar('1');
			else putchar('0');
		}
		puts("");
	}
	return 0;
}
