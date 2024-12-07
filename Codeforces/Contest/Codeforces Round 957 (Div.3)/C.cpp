#include <bits/stdc++.h>
using namespace std;
int t, n, k, m;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
int main() {
	t = read();
	while (t--) {
		n = read(), k = read(), m = read();
		for (int i = n; i > k; i--) printf("%d ", i);
		for (int i = 1; i <= k; i++) printf("%d ", i);
		putchar('\n');
	}
	return 0;
}